class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        
        // make adj list from all the edges given to us
        vector<int> adj[n];     
        vector<int> ans; 
        for (auto it : p) {
            int u = it[0], v = it[1];
            adj[v].push_back(u); 
        }
        // from here we use KAHN'S ALGORITHM to make topo list in ans
        vector<int> indegree(n, 0);         
        for (int i = 0; i < n; i++) 
            for (auto it : adj[i]) indegree[it]++;

        queue<int> q;
        for (int i = 0; i < n; i++) 
            if (indegree[i] == 0) q.push(i);

        while (!q.empty()) {
            int node = q.front(); q.pop();  
            ans.push_back(node);            

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        // if there is a cycle in graph the all indegree will never become 0
        // so our ans size will be less than n, hence invalid for our ques we return {}
        return ans.size() == n ? ans : vector<int>{};
      }
};
/*
The algorithm can be summarized as -

    Form adjacency list graph from P & compute indegree for each node
    
    For the 1st level of BFS iteration, fill up the queue with courses having indegreei = 0, 
    i.e, courses with no prerequisites
    
    At each iteration, pop & add the course from queue to ordering ans
    
    Decrement indegree of each course for which current course was prerequisite. 
    
    If the indegree for those courses becomes 0, we can take it next by adding it to queue
    
    Continue the process till queue isn't empty
    
    Finally, return ans if it contains N courses denoting all courses can be finished, otherwise we
    know that the graph contains cycle & its impossible to finish all courses in which case we return []
*/
