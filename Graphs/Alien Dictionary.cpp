// https://practice.geeksforgeeks.org/problems/alien-dictionary/1
class Solution{
    private:
    // function to find toposort for a DAG
    // https://practice.geeksforgeeks.org/problems/topological-sort/1
    vector<int> topoSort(int V, vector<int> adj[]) {
        
	    vector<int> indegree(V, 0);         
	    for (int i = 0; i < V; i++) 
	        for (auto it : adj[i]) indegree[it]++;
	    
	    queue<int> q;
	    for (int i = 0; i < V; i++) 
	        if (indegree[i] == 0) q.push(i);
	    
	    vector<int> ans;    
	    while (!q.empty()) {
	        int node = q.front(); q.pop();  
	        ans.push_back(node);    
	        for (auto it : adj[node]) {
	            indegree[it]--;
	            if (indegree[it] == 0) q.push(it);
	        }
	    }
	    return ans;
	}
    
    public:
    string findOrder(string dict[], int N, int K) {
        
        // make adj list of all letters
        // eg. for 2 cons words bbc and aca -> we can conclude that b appear before a in this dict
        // so b -> a is a DAG edge and we store this in adj list, do this for all adjacent words
        // make adj list of numbers map letter as number 0 - 25
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++) {
            
            string s1 = dict[i], s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        // find toposort of the adj list
        vector<int> toposort;
        toposort = topoSort(K, adj);
        
        // convert numbers again to char 
        string ans = "";
        for (int it : toposort) {
            ans.push_back(char(it + 'a'));
        }
        return ans;
    }
};
