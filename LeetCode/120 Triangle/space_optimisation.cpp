// SPACE Optimisation - O(N*N) --> O(N) SPACE
// since we need the prev saved states of only one row below the row we do operations
// so we can recuce space to o(n)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<int> prev(n);        // dp array saves prev row states, i + 1th row

        // base case : if (i == n - 1) return triangle[i][j]; 
        // save all states in prev dp array
        for (int j = 0; j < n; j++) 
            prev[j] = triangle[n - 1][j];
        
        // nth row already taken in base case so start iteration from n - 2th row
        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 0);         // dummy array saves curr states and then pass it to prev
            for (int j = i; j >= 0; j--) { 

                int down = triangle[i][j] + prev[j];       
                int diag = triangle[i][j] + prev[j + 1];

                curr[j] = min(down, diag);
            }
            prev = curr;
        }
        return prev[0];
    }
};

/* TABULATION - BOTTOM UP
we did from 0 -> n in memo so bottom up will go from n - 1 till 0
since starting point is fixed and end point is variable

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));

        // base case : if (i == n - 1) return triangle[i][j]; 
        // save all states in last row of dp
        for (int j = 0; j < n; j++) 
            dp[n - 1][j] = triangle[n - 1][j];
        
        // nth row already taken in base case so start iteration from n - 2th row
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) { 

                int down = triangle[i][j] + dp[i + 1][j];       
                int diag = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
};*/

/* MEMOIZATION SOLN
class Solution {
public:
    int n;
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {

        if (i == n - 1) return triangle[i][j];
        if (dp[i][j] != INT_MIN) return dp[i][j];

        int down = triangle[i][j] + f(i + 1, j, triangle, dp);
        int diag = triangle[i][j] + f(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return f(0, 0, triangle, dp);
    }
};*/
