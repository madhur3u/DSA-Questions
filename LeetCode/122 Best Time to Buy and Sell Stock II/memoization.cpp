class Solution {
public:
    int f(int i, int buy, vector<int>& a, vector<vector<int>>& dp) {

        if (i == a.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        // if we need to buy the stock
        // 2 ways either buy at ith day or not, call for both
        // take / not take cases
        if (buy) {
            // in take, since we buy stock we add -a[i] into profit as we are buying
            // change buy state to 0 as in next calls we first need to sell stock before buying another
            int take = -a[i] + f(i + 1, 0, a,dp); 
            int notTake =  0 + f(i + 1, 1, a,dp);   // not buying, buy state same as we will buyin next call

            profit = max(take, notTake);
        }
        // if we need to sell the stock
        // 2 ways either sell at ith day or not, call for both
        else {
            // in take, since we sell stock we add a[i] into profit as we are selling
            // change buy state to 1 as in next calls we first need to buy stock 
            int take = a[i] + f(i + 1, 1, a,dp); 
            int notTake = 0 + f(i + 1, 0, a,dp);   // not selling, buy state same as we will buyin next call

            profit = max(take, notTake);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& a) {
        
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, a, dp);
    }
};
