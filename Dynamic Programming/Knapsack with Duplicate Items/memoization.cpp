// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
class Solution{
public:
    int f(int i, int w, int wt[], int val[], vector<vector<int>>& dp) {
        
        // BASE CASES
        if (i == 0) {
            // if we reach 0 means only 1 element left, we will take it if we can 
            // so check with w and return val multiply by no. of time we can take it i.e. (w / wt[0])
            // since we can take a element multiple times
            if (wt[0] <= w) return val[0]*(w / wt[0]);
            else return 0;      // if we cant take it return 0
        }
        if (dp[i][w] != -1) return dp[i][w];    // if state already saved in dp return that
        
        // not taking curr el so nothing added and weight not reduced, index reduced
        int notTake = 0 + f(i - 1, w, wt, val, dp);
        
        // for taking, we can take only if element weight is less than or equal to w
        // so initially make it -1
        // and take only if cond satisfy
        // do not reduce index as we can take an element multiple times
        int take = -1;
        if (wt[i] <= w) take = val[i] + f(i, w - wt[i], wt, val, dp);
        
        // take max of both return and save in dp
        return dp[i][w] = max(take, notTake);
    }
    int knapSack(int n, int W, int val[], int wt[]) {
        
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return f(n - 1, W, wt, val, dp);
    }
};
