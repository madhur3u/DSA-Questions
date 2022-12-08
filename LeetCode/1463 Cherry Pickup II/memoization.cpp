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
};

/* RECURSIVE SOLUTION
// TRY ALL PATHS
class Solution {
public:
    int n, m;
    int f(int i, int j1, int j2, vector<vector<int>>& grid) {
        
        // BASE CASES
        if (j1 < 0 || j1 >= m || j2 < 0 | j2 >= m) return -1e9;   // base case index out of grid
        if (i == n - 1) {                                         // base case we are in last row
            if (j1 == j2) return grid[i][j1];               // both robots in same cell
            else          return grid[i][j1] + grid[i][j2]; // both robots in diff cell
        }

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
                currMaxSum = max(currMaxSum, grid[i][j1] + f(i + 1, j1 + d1, j2 + d2, grid));
            else 
                currMaxSum = max(currMaxSum, grid[i][j1] + grid[i][j2] + f(i + 1, j1 + d1, j2 + d2, grid));
        }
        return currMaxSum;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(); 
        m = grid[0].size();
        return f(0, 0, m - 1, grid);
    }
};*/
