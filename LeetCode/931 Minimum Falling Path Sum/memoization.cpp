class Solution {
public:
    int n, m;
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {

        if (j < 0 || j >= n)     return 1e9;            // out of grid case, return a bigger number
        if (i == 0)              return grid[i][j];     // base case 1st row reached
        if (dp[i][j] != INT_MIN) return dp[i][j];       // if state already saved in dp

        // all 3 calls, since we go from n - 1 to zero so up, left diag, right diag
        int up    = grid[i][j] + f(i - 1, j, grid, dp);
        int right = grid[i][j] + f(i - 1, j + 1, grid, dp);
        int left  = grid[i][j] + f(i - 1, j - 1, grid, dp); 

        // save in dp and return min of all 3 calls
        return dp[i][j] = min(up, min(right, left));
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));     // dp to save states

        int ans = INT_MAX;
        
        // we dont have a fixed start or end point
        // so we traverse from  n - 1 to 0
        // and find answer from each cell in n - 1th row
        // return min of all  
        for (int j = 0; j < n; j++) {
            ans = min(ans, f(n - 1, j, grid, dp));
        }
        return ans;
    }
};
