class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();       // no. of nodes
        vector<int> vis(n, -1);     // -1 : uncoloured, 0 : color 1, 1 : color 2
        
        // traverse in all nodes in case if graph not connected
        for (int i = 0; i < n; i++) {

            // if current node is not coloured
            if (vis[i] == -1) {
                // colour it with color 1 and check in bfs if it is bipartitie graph
                // if bfs return false means graph is not bpt, return false
                vis[i] = 0;
                if (!bfs(i, graph, vis)) return false;
            }
        }
        return true;
    }
    // bfs fn, logic is that we will traverse level wise
    // and check all connected nodes
    // if the node is not visited then color it with the opposite color of current node
    // if node is already visited check if node is coloured with opposite colour of current node
    // this way all cycles will be checked 
    bool bfs(int i, vector<vector<int>>& graph, vector<int>& vis) {

        queue<int> q;   // bfs q
        q.push(i);      // push the 1st node

        // bfs traversal
        while (!q.empty()) {

            int node = q.front(); q.pop();  // extract node and pop
            int color = vis[node];          // color of current node 

            // iterate in all connected nodes of node
            for (auto it : graph[node]) {
                // if node not visited earlier, color it and push in q
                if (vis[it] == -1) {
                    q.push(it);
                    vis[it] = !color;
                }
                // if node is coloured and has same color as current node means two adj nodes has same color
                // return false
                else if (vis[it] == color) return false;
            }
        }
        return true;
    }
};
