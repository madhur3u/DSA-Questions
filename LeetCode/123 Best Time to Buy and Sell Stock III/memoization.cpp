class Solution {
public:
    // k are the no. of transanction we can have i,e, max 2
    int f(int i, int buy, int k, vector<int>& a, vector<vector<vector<int>>>& dp) {

        if (i == a.size() || k == 0) return 0;          // if we reach out or transactions over
        if (dp[i][buy][k] != -1) return dp[i][buy][k];

        int profit = 0;

        // if we need to buy the stock
        // 2 ways either buy at ith day or not, call for both
        // take / not take cases
        if (buy) {
            // in take, since we buy stock we add -a[i] into profit as we are buying
            // change buy state to 0 as in next calls we first need to sell stock before buying another
            // k wont change as we complete a transaction when we sell
            int take = -a[i] + f(i + 1, 0, k, a, dp); 
            int notTake =  0 + f(i + 1, 1, k, a, dp);   // not buying, buy state same as we will buyin next call

            profit = max(take, notTake);
        }
        // if we need to sell the stock
        // 2 ways either sell at ith day or not, call for both
        else {
            // in take, since we sell stock we add a[i] into profit as we are selling
            // change buy state to 1 as in next calls we first need to buy stock 
            // when selling we completed a trns. so reduce k by 1 for next call
            int take = a[i] + f(i + 1, 1, k - 1, a, dp); 
            int notTake = 0 + f(i + 1, 0, k, a, dp);   // not selling, buy state same as we will buyin next call

            profit = max(take, notTake);
        }
        return dp[i][buy][k] = profit;
    }
    int maxProfit(vector<int>& a) {
        
        int n = a.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(3,-1)));        
        return f(0, 1, 2, a, dp);
    }
};
