class Solution {
  public:
    vector<int> ans;
    // dfs fn
    void dfs(int node, vector<int> adj[], int visited[]){
        
        // push curr node in ans, mark as visited
        ans.push_back(node);
        visited[node] = 1;
        
        // check all nodes connected to node in adj list, if the are not visited dfs call
        for (int it : adj[node]) {
            if (!visited[it]) dfs(it, adj, visited);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int visited[V] = {0};
        dfs(0, adj, visited);
        return ans;
    }
};
