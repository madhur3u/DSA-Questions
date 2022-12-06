// https://github.com/madhur3u/DSA-Questions/blob/main/LeetCode/62%20Unique%20Paths/dp_all.cpp

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;   // 1st or last cell has obstacle
        vector<int> dp(n);

        for (int i = 0; i < m; i++) {

            vector<int> temp(n, 0);     // temp vector for current row
            
            for (int j = 0; j < n; j++) {

                // already computed temp[0] = 1, also 
                if (grid[i][j] == 1) continue;
                // when obstacle we continue as we have already store 0 in temp vector so directly continue
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }     

                // compute paths from up and left directions 
                int up = 0, left = 0;   
                if (i > 0) up = dp[j];              // up we can get from prev row i.e. dp matrix
                if (j > 0) left = temp[j - 1];      // left we can get using curr row j - 1 cell, from temp

                temp[j] = up + left;                // compute total paths, store in temp
            }
            dp = temp;                              // store curr row paths in dp for next iteration
        }
        return dp[n - 1];
    }
};

/* RECURSIVE - MEMO SOLUTION - SAVE ALREADY SOLVED SUBPROBLEMS IN DP MATRIX
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {

        if (i == 0 && j == 0) return 1;                     // base case, return 1 path
        // index out of grid case OR obstacle in curr cell, return 0 path
        if (i < 0 || j < 0 || grid[i][j] == 1) return 0;    
        if (dp[i][j] != -1) return dp[i][j];    // if state already saved before / subproblem solved

        int up = dfs(i - 1, j, dp, grid);             // take one call to upwards dir 
        int left = dfs(i, j - 1, dp, grid);           // one call in left direction

        return dp[i][j] = up + left;            // return sum of paths we get from both calls
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dfs(m - 1, n - 1, dp, grid);
    }
};*/
