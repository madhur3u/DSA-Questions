class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n));     // dp to save states

        for (int j = 0; j < n; j++)     // base case : if (i == 0) return grid[i][j];
            dp[0][j] = grid[0][j];
        
        // iterate from 1st row till last, 0th row already saved in base case loop
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                // compute all 3 possibe dir
                // if j out of grid put int max
                int up    = grid[i][j] + dp[i - 1][j];
                int right = (j + 1 < n)  ? grid[i][j] + dp[i - 1][j + 1] : INT_MAX;
                int left  = (j - 1 >= 0) ? grid[i][j] + dp[i - 1][j - 1] : INT_MAX; 

                // store the min in dp
                dp[i][j] = min(up, min(right, left));
            }
        }
        // when above loop ends, we will have all 4 answer in last row of dp grid
        // compare each cell in last row and return minimum
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};
