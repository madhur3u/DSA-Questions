class Solution {
public:
    int n;
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {

        if (i == n - 1) return triangle[i][j];      // base case when we at last row return just cell val
        if (dp[i][j] != INT_MIN) return dp[i][j];   // if state already saved in dp

        // we traverse at jth -> down or j+1th -> diagonal dir only from each cell
        int down = triangle[i][j] + f(i + 1, j, triangle, dp);
        int diag = triangle[i][j] + f(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diag);  // take min of both calls and also save in dp
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN)); // dp n x n, all int_min 
        return f(0, 0, triangle, dp);
    }
};

/* SIMPLE RECURSIVE SOLN 
   GO FROM 0 ROW TILL LAST ROW AND FORM ANS WHILE BACKTRACKING
class Solution {
public:
    int n;
    int f(int i, int j, vector<vector<int>>& triangle) {

        if (i == n - 1) return triangle[i][j];

        int down = triangle[i][j] + f(i + 1, j, triangle);
        int diag = triangle[i][j] + f(i + 1, j + 1, triangle);

        return min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        return f(0, 0, triangle);
    }
};*/
