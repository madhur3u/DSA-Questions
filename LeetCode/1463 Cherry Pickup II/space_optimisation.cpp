// TABULATION APPROACH 
// Time Complexity: O(N*M*M)*9 --- Space Complexity: O(M*M) for dp
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        
        // dp[n][m][m] --> since we use only i + 1th row each time we compute
        // so no need to make a 3d dp
        // we can do it using a 2d dp of m x m which store the states of next row -> i + 1th row
        // curr use t store states of ith row --> then we do next = curr before next iteration
        vector<vector<int>> next(m, vector<int>(m,0));
        vector<vector<int>> curr(m, vector<int>(m,0));

        // FORMING DP LAST ROW WITH BASE CASE
        for (int j1 = 0; j1 < m; j1++)
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2) next[j1][j2] = grid[n - 1][j1];           // both robots in same cell
            else  next[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2]; // diff cell
        }

        // n - 1 in base case
        // traverse from n - 2
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
                            ans += next[j1 + d1][j2 + d2];
                        else
                            ans += -1e9;
                        currMaxSum = max(currMaxSum, ans);  // maximise sum
                    }
                    curr[j1][j2] = currMaxSum;     // store max sum for curr i, j1, j2 combination in dp
                }
            }
            next = curr;
        }
        return next[0][m - 1]; // return using the fixed starting corrdinates of both robots
    }
};
