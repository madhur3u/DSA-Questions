class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;    // base cases when array exhausted hence [n][j]

        // two loops as 2 variables n x 2
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {

                // memo code with calls changed to dp
                int profit = 0;
                if (buy) {
                    int take    = -a[i] + dp[i + 1][0];
                    int notTake =  0 + dp[i + 1][1]; 
                    profit = max(take, notTake);
                }
                else {
                    int take    = a[i] + dp[i + 1][1]; 
                    int notTake = 0 + dp[i + 1][0]; 
                    profit = max(take, notTake);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
