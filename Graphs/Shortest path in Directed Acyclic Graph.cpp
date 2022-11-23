// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// we are doing this using topo sort as we need to find shortest path from 1st node
// and topo sort will give us the nodes in order so 1st node 0 will be the top os stack if dfs is done
// so using that stack we can reach each node in sequence
class Solution {
    
    private:
    // toposort DFS method, toposort stored in stack
    void topoSort(int node, bool vis[], stack<int>& st, vector<pair<int, int>> adj[]) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) topoSort(v, vis, st, adj);
        }
        st.push(node);
    }
    
    public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& E){
        
        // make the adj list with weights as 2nd element of pair
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) {
            int u = E[i][0];
            int v = E[i][1];
            int wt = E[i][2];
            adj[u].push_back({v, wt});
        }
        // topo sort the nodes
        // O(N+M)
        bool vis[N] = {0};
        stack<int> st;
        for (int i = 0; i < N; i++)
            if (!vis[i]) topoSort(i, vis, st, adj);
        
        // distance array creation and storing distance using topo sort
        // O(N+M)
        vector<int> dis(N, 1e9);
        dis[0] = 0;                     // base node from which we start distance to itself is zero
        
        // loop till all nodes checked means st is empty
        while (!st.empty()) {
            // extract node and pop
            int node = st.top(); st.pop();
            
            // for curr node traverse in adj list and extract distance and node for each pair
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                
                // now the distance of the 0 -> v, will be the distance travelled till now => dis[node]
                // + the distnace we will travel in curr v node => wt
                // so total distance will be dis[node] + wt
                // but we might have reached a better solution before curr sol which may have less distance
                // so do min with the curr distance stored, as we store 10**9 initially in dis so we will always store the min distance
                dis[v] = min(dis[v], dis[node] + wt);
            }
        }
        // for all those nodes which were unreachable from 0th node the dis will still be 10**9
        // update it with-1
        for (auto& it : dis) if (it == 1e9) it = -1;
        return dis;
    }
};
