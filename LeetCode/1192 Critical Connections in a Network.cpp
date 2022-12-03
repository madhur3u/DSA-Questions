// Tarjan's Algorithm of time in and low time
// https://www.youtube.com/watch?v=qrAub5z8FeA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=54
// we detect cycles and take those edges which are not part of a cycle
// PLEASE SEE VIDEO AND DO IN PAPER
class Solution {
    int timer = 1;  // this tell us time at which we insert a node or time at which node traversed in dfs
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> tin(n, 0);  // In Time
        vector<int> low(n, 0);  // Low Time
        vector<int> vis(n, 0);  // Visited Array
        vector<vector<int>> bridges;

        // make adj list from edges
        vector<int> adj[n];
        for (auto& itr : connections) {
            int u = itr[0];
            int v = itr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // dfs will push all bridges
        dfs(0, -1, vis, tin, low, bridges, adj);
        return bridges;
    }
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, 
             vector<int>& low, vector<vector<int>>& bridges, vector<int> adj[]) {

        vis[node] = 1;      // mark node visited
        tin[node] = timer;  // set in time of node as timer
        low[node] = timer;  // set low time also to timer, initially in time and low time same
        timer++;            // inc timer for next call

        // iterate in all adjNode of node
        for (auto& adjNode : adj[node]) {
            if (adjNode == parent) continue;    // dont do anything for parent

            // if the adjNode is not visited
            if (vis[adjNode] == 0) {
                
                // call dfs for this adjNode with parent as node
                dfs(adjNode, node, vis, tin, low, bridges, adj);

                // in backtracking set the low of node as lowest of node and adjnode lows
                low[node] = min(low[node], low[adjNode]);

                // if low[adjNode] > in time of node
                // it means we cannot reach adjNode from anyother path than node --- adjNode
                // so node --- adjNode is a bridge, push in bridges
                if (low[adjNode] > tin[node]) bridges.push_back({node, adjNode});
            }
            else {
                // if adjNode is already visited 
                // minimise the low of node
                low[node] = min(low[node], low[adjNode]);
            }
        }
    }
};
