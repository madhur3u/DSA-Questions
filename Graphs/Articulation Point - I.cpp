// https://www.youtube.com/watch?v=j1QDfU21iZk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=55
// https://practice.geeksforgeeks.org/problems/articulation-point-1/1
class Solution {
    int timer = 1;
  public:
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, 
             vector<int> adj[], vector<int>& mark) {

        vis[node] = 1;      // mark node visited
        tin[node] = timer;  // set in time of node as timer
        low[node] = timer;  // set low time also to timer, initially in time and low time same
        timer++;            // inc timer for next call
        int child = 0;

        // iterate in all adjNode of node
        for (auto& adjNode : adj[node]) {
            if (adjNode == parent) continue;    // dont do anything for parent

            // if the adjNode is not visited
            if (vis[adjNode] == 0) {
                
                // call dfs for this adjNode with parent as node
                dfs(adjNode, node, vis, tin, low, adj, mark);

                // in backtracking set the low of node as lowest of node and adjnode lows
                low[node] = min(low[node], low[adjNode]);

                // if low[adjNode] >= in time of node
                // it means node is a art point and adjNode can reach above node only thr node
                // so node is a art point, mark it as 1
                if (low[adjNode] >= tin[node] && parent != -1) mark[node] = 1;
                
                child++;
            }
            else {
                // if adjNode is already visited 
                // minimise the low of node using tin of adjNode // SEE VEDEO
                low[node] = min(low[node], tin[adjNode]);
            }
        }
        if (child > 1 && parent == -1) mark[node] = 1;  // source node case
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        int n = V;
        
        vector<int> tin(n, 0);  // In Time
        vector<int> low(n, 0);  // Low Time
        vector<int> vis(n, 0);  // Visited Array
        vector<int> mark(n, 0);
        
        dfs(0, -1, vis, tin, low, adj, mark);
        
        vector<int> art_points;
        for (int i = 0; i < n; i++) 
            if (mark[i] == 1) art_points.push_back(i);
        
        if (art_points.size() == 0) art_points.push_back(-1);
        
        return art_points;
    }
};
