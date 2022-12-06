class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();        
        vector<int> prev(m, 0);  // oneD dp to save states -> since we need to save only prev row states so 1D

        for (int i = 0; i < n; i++) {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0) { curr[0] = grid[0][0]; continue; }  // base case saved in 1st cell

                // set to a large number initially as we do min
                // in edges only one of up and left will be done
                int up = 1e9, left = 1e9;   

                if (i > 0) up   = grid[i][j] + prev[j];         // move up -> take curr element and prev state
                if (j > 0) left = grid[i][j] + curr[j - 1];     // move left -> curr + prev saved state 

                curr[j] = min(up, left);   // take min of both and store in curr state dp
            }
            prev = curr;
        }
        return prev[m - 1];
    }
};
/* RECURSION - MEMOIZATION SOLUTON
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
};*/
