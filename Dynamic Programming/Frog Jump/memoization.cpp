// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
#include <bits/stdc++.h> 
int dfs(int i, vector<int>& dp, vector<int>& h) {
    
    if (i == 0) return 0;                // base case
    if (dp[i] != -1) return dp[i];       // if ans already stored in dp 
    
    int jump1, jump2 = INT_MAX;
    
    // jump 1, take 1 step and add height diff in 1 step
    jump1 = dfs(i - 1, dp, h) + abs(h[i] - h[i - 1]);
    
    // jump 2 only when index > 1 as we dont want to take -1 case when i = 1
    // add height diff of 2 jumps using heights array h
    if (i > 1) jump2 = dfs(i - 2, dp, h) + abs(h[i] - h[i - 2]);
    
    return dp[i] = min(jump1, jump2);    // return min of both
}
int frogJump(int n, vector<int> &heights) {
    
    vector<int> dp(n + 1, -1);
    return dfs(n - 1, dp, heights);
}
