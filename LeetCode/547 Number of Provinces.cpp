class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();             // number of nodes
        vector<bool> visited(n + 1, false);     // visited arr, n + 1 as 1 indexed
        int ans = 0;                            // store no of provinces

        // traverse from i = 1 : n, all nodes 
        // for each node we check if visited or not, if not we do a dfs traversal for that node, inc ans
        // using this we will mark all nodes visisted in a province, so we will have if cond true
        // only no. of province times
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i, isConnected, visited), ans++;
        }
        return ans;
    }
    // dfs traversal
    void dfs(int i, vector<vector<int>>& a, vector<bool>& visited){
    
        // mark curr node true
        visited[i] = true;

        // traverse in the ith row, check if its 1 in adj matrix
        // if not visited dfs call
        for (int j = 1; j <= a.size(); j++) {
            if (i != j && a[i - 1][j - 1] && !visited[j]) dfs(j, a, visited);
        }
    }
};
