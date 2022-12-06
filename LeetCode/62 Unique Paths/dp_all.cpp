// SPACE - OPTIMIZED SOLUTION
class Solution {
public:
    int uniquePaths(int m, int n) {

        // since while tabulation we saw we only need the prev row to access the up element
        // so we can solve using 1D dp vector
        vector<int> dp(n, 0);  

        for (int i = 0; i < m; i++) {

            vector<int> temp(n, 0);     // temp vector for current row
            temp[0] = 1;                // base case set 0th el to 1
            
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) continue;     // already coputed temp[0] = 1

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

/* TABULATON - REMOVING RECURSIVE STACK SPACE
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n));  // dp vector to save prev states
        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0) continue;

            int up = 0, left = 0;

            if (i > 0) up = dp[i - 1][j];
            if (j > 0) left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
        return dp[m - 1][n - 1];
    }
};
*/

/* RECURSIVE - MEMO SOLUTION - SAVE ALREADY SOLVED SUBPROBLEMS IN DP MATRIX
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp) {

        if (i == 0 && j == 0) return 1;         // base case, return 1 path
        if (i < 0 || j < 0) return 0;           // index out of grid case, return 0 path
        if (dp[i][j] != -1) return dp[i][j];    // if state already saved before / subproblem solved

        int up = dfs(i - 1, j, dp);             // take one call to upwards dir 
        int left = dfs(i, j - 1, dp);           // one call in left direction

        return dp[i][j] = up + left;            // return sum of paths we get from both calls
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));  // dp vector to save prev states
        return dfs(m - 1, n - 1, dp);
    }
};
*/

/* RECURSIVE SOLUTION - TRAVERSE AND COUNT ALL PATHS
we go from last cell to 1st cell and count no. of paths recursively
since we go from last to 1st hence we reverse the dir to up and left from down and right

class Solution {
public:
    int dfs(int i, int j) {

        if (i == 0 && j == 0) return 1; // base case, return 1 path
        if (i < 0 || j < 0) return 0;   // index out of grid case, return 0 path

        int up = dfs(i - 1, j);         // take one call to upwards dir 
        int left = dfs(i, j - 1);       // one call in left direction

        return up + left;               // return sum of paths we get from both calls
    }
    int uniquePaths(int m, int n) {
        return dfs(m - 1, n - 1);
    }
};
*/
