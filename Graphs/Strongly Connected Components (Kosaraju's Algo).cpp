// https://www.youtube.com/watch?v=R6uoSjZ2imo&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=53
// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
class Solution {
public:
    // DFS FN FOR STEP 1
    // normal dfs traversal with visited array
    // store element in stack while backtracking -> storing element acc to finish time
    int dfs1(int i, vector<int>& vis, vector<int> adj[], stack<int>& st) {

        vis[i] = 1;
        for (auto& adjNode : adj[i]) {
            if (!vis[adjNode]) dfs1(adjNode, vis, adj, st);
        }
        st.push(i);
    }
    // DFS FN FOR STEP 3
    // we just need to perform dfs and mark visited nodes
    // since graph reversed so in one call we can only traverse one scc only
    int dfs2(int i, vector<int>& vis, vector<int> adjT[]) {

        vis[i] = 1;
        for (auto& adjNode : adjT[i]) {
            if (!vis[adjNode]) dfs2(adjNode, vis, adjT);
        }
    }
    int kosaraju(int n, vector<int> adj[]) {
        
        // STEP 1 : FIND FINISHING TIME OF ALL NODES USING DFS
        // we can use simple dfs and and store node in backtracking in stack
        // the top of stack contains the element which finished last
        vector<int> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
            if (!vis[i]) dfs1(i, vis, adj, st);
            
        // STEP 2 : REVERSE THE GRAPH edges
        vector<int> adjT[n];
        for (int i = 0; i < n; i++)
        for (auto& it : adj[i]) adjT[it].push_back(i);  // from i --> it edge to it --> i
        
        // STEP 3 : do dfs and count no. of SCCs in reverse graph
        // since we reversed the edges now one scc wont be able to reach another scc
        // so we call dfs for every unvisited node in stack and no. of times we make call == no. of scc
        vis.clear();    // clear vis vector and resize to n
        vis.resize(n, 0); 
        int SCC = 0;
        while (!st.empty()) {
            int node = st.top();
            if (!vis[node]) {
                SCC++;
                dfs2(node, vis, adjT);
            }
            st.pop();
        }
        return SCC;
    }
};
