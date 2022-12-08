class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();

        // 1D dp to save states
        // since we only need answer formed in one row above from 2d dp 
        // so we can store prev states in just a oneD dp 
        vector<int> prev(n), curr(n);     

        for (int j = 0; j < n; j++)     // base case : if (i == 0) return grid[i][j];
            prev[j] = grid[0][j];
        
        // iterate from 1st row till last, 0th row already saved in base case loop
        // store curr state in a dummy vector curr
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                // compute all 3 possibe dir
                // if j out of grid put int max
                int up    = grid[i][j] + prev[j];
                int right = (j + 1 < n)  ? grid[i][j] + prev[j + 1] : INT_MAX;
                int left  = (j - 1 >= 0) ? grid[i][j] + prev[j - 1] : INT_MAX; 

                // store the min in dp
                curr[j] = min(up, min(right, left));
            }
            prev = curr;
        }
        // when above loop ends, we will have all 4 answer in last row of dp grid
        // compare each cell in last row and return minimum
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, prev[j]);
        }
        return ans;
    }
};
