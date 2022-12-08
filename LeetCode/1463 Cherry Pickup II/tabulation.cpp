// TABULATION APPROACH 
// Time Complexity: O(N*M*M)*9 --- Space Complexity: O(N*M*M) for dp
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        
        int dp[n][m][m];

        // FORMING DP LAST ROW WITH BASE CASE
        for (int j1 = 0; j1 < m; j1++)
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2) dp[n - 1][j1][j2] = grid[n - 1][j1];           // both robots in same cell
            else  dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2]; // diff cell
        }

        // n - 1 in base case
        // traverse from n - 2
        // for 3d dp we have 3 for loops for i, j1, j2
        // after that paste memo code and change accordingly
        for (int i = n - 2; i >= 0; i--){
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {

                    int currMaxSum = 0;

                    // all 9 paths combination from curr pos of both robots
                    for (int d1 = -1; d1 <= 1; d1++)
                    for (int d2 = -1; d2 <= 1; d2++) {

                        int ans;
                        // form ans acc to if both cells same or diff
                        if (j1 == j2)   ans = grid[i][j1] ;
                        else            ans = grid[i][j1] + grid[i][j2];

                        // if we are in grid then only we can add prev result from dp
                        // else add a big -ve number to ans
                        if (j1 + d1 >= 0 && j1 + d1 < m && j2 + d2 >= 0 && j2 + d2 < m)
                            ans += dp[i + 1][j1 + d1][j2 + d2];
                        else
                            ans += -1e9;
                        currMaxSum = max(currMaxSum, ans);  // maximise sum
                    }
                    dp[i][j1][j2] = currMaxSum;     // store max sum for curr i, j1, j2 combination in dp
                }
            }
        }
        return dp[0][0][m - 1]; // return using the fixed starting corrdinates of both robots
    }
};
/* MEMOIZATION - RECURSIVE SOLUTION
// TRY ALL PATHS, SAVE STATES IN 3D DP
class Solution {
public:
    int n, m;
    int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        
        // BASE CASES
        if (j1 < 0 || j1 >= m || j2 < 0 | j2 >= m) return -1e9;   // base case index out of grid
        if (i == n - 1) {                                         // base case we are in last row
            if (j1 == j2) return grid[i][j1];               // both robots in same cell
            else          return grid[i][j1] + grid[i][j2]; // both robots in diff cell
        }
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];  // if state already saved in dp

        // EXPLORE THE PATHS
        // rob 1 can move to 3 directions and same for rob 2
        // so for 1 dir of rob1 we can move rob2 3 dirs -> so total 3 x 3 = 9 moves from each row
        int currMaxSum = 0;
        for (int d1 = -1; d1 <= 1; d1++)
        for (int d2 = -1; d2 <= 1; d2++) {

            // in these 2 loop swe will have 9 combinations of (d1, d2)
            // we add d1 in j1 and d2 in j2 to get all combinations we can have from curr pos of robots
            // 2 conditions inside
            // if both on same cell we add only once the cell value i.e. no. of cherries
            // if both on diff cells add both vals
            if (j1 == j2)
                currMaxSum = max(currMaxSum, grid[i][j1] + f(i + 1, j1 + d1, j2 + d2, grid, dp));
            else 
                currMaxSum = max(currMaxSum, grid[i][j1] + grid[i][j2] + f(i + 1, j1 + d1, j2 + d2, grid, dp));
        }
        return dp[i][j1][j2] = currMaxSum;      // save state and return
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(); 
        m = grid[0].size();
        
        // since we deal with 3 variables at each call i, j1, j2
        // hence we need a 3d dp --> dp[n][m][m]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m - 1, grid, dp);
    }
};*/
