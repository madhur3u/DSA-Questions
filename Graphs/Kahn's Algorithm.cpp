// https://practice.geeksforgeeks.org/problems/topological-sort/1

// O(V + E) time
// O(V) space
class Solution {
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    
	    // create indegree array by traversing in adj list
	    vector<int> indegree(V, 0);         
	    for (int i = 0; i < V; i++) 
	        for (auto it : adj[i]) indegree[it]++;
	    
	    // q for bfs traversal, q will have all nodes with indegree zero
	    // in a DAG we are gauranteed to have atleast one node with indegree 0
	    queue<int> q;
	    for (int i = 0; i < V; i++) 
	        if (indegree[i] == 0) q.push(i);
	    
	    vector<int> ans;    // vector to store ans
	    
	    // bfs traversal
	    while (!q.empty()) {
	        int node = q.front(); q.pop();  // extract node and pop
	        ans.push_back(node);            // push this node in ans as it had 0 indegree
	        
	        // traverse in all connected nodes of current node
	        // we reduce the indegree of the connected nodes and push in q if indegree of any node become 0
	        for (auto it : adj[node]) {
	            indegree[it]--;
	            if (indegree[it] == 0) q.push(it);
	        }
	    }
	    return ans;
	}
};
