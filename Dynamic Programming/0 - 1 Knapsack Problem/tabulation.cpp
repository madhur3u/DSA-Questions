// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
class Solution {
    public:
    int knapSack(int W, int wt[], int val[], int n) { 
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        // forming 1st row using base case
        // if (i == 0) { if (wt[0] <= w) return val[0]; else 0, so initailly all as 0
        // now we make in 1st row every index from wt[0] to w equal to val[0]
        for (int i = wt[0]; i <= W; i++)
            dp[0][i] = val[0];
        
        // 2 loops as 2 indices to deal with i and w
        // i start from 1 as 0 taken in base case
        // paste the memo codewith changes
        for (int i = 1; i < n; i++) {
            for (int w = 0; w <= W; w++) {
                
                int notTake = 0 + dp[i - 1][w];
                int take = -1;
                if (wt[i] <= w) take = val[i] + dp[i - 1][w - wt[i]];
                
                dp[i][w] = max(take, notTake);
            }
        }
        return dp[n - 1][W];
    }
};
/*
Time Complexity: O(N*W)
Reason: There are two nested loops

Space Complexity: O(N*W)
Reason: We are using an external array of size ‘N*W’. Stack Space is eliminated.
*/
