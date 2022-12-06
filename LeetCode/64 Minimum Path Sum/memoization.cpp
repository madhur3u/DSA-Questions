class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {

        if (i == 0 && j == 0) return grid[0][0];    // base case
        if (i < 0 || j < 0)   return 1e9;           // if index out of bounds, return a big number so wont be taken
        if (dp[i][j] != -1)   return dp[i][j];      // if state already computed

        int up   = grid[i][j] + dfs(i - 1, j, grid, dp);    // move up -> take curr element and dfs to up
        int left = grid[i][j] + dfs(i, j - 1, grid, dp);    // move left -> curr + dfs to left

        return dp[i][j] = min(up, left);            // return minimum of both 
    }
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();        
        vector<vector<int>> dp(n, vector<int>(m, -1));  // dp to save states
        return dfs(n-1, m-1, grid, dp);
    }
};
