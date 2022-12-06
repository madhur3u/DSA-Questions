// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

int dfs(int idx, int row, vector<vector<int>> &points, vector<vector<int>>& dp) {
    
    if (row < 0 ) return 0;                        // base case
    if (dp[row][idx] != -1) return dp[row][idx];   // state already computed earlier return that 
    
    // computng max for curr row
    // declare maxP for max points from row till 0th row
    int maxP = 0;
    
    // iterate in all 3 tasks
    // do not take the task which we did previously, therefore i != idx
    // also for 0 row, dfs call will go to -ve row and return 0, so we take max of the 2 tasks we have
    for (int i = 0; i < 3; i++) {
        if (i != idx) maxP = max(maxP, points[row][i] + dfs(i, row - 1, points, dp));
    }
    // save max in dp, return
    return dp[row][idx] = maxP;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    // dp 2d vector to save states, of size 4 as we take 3rd index as no task performed which is initial
    // doing recursion from n - 1 till 1
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return dfs(3, n - 1, points, dp);
}
