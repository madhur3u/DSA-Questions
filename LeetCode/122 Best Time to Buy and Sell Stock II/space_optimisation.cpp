/*
Time Complexity: O(n * 2) --> O(n)
Reason: There are two nested loops that account for O(N*2) complexity

Space Complexity: O(4) --> O(1)
Reason: We are using an external array of size ‘2’.
*/
class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int n = a.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // since we only use buy state of prev and curr row so 2 1d dp
        vector<int> prev(2, 0), curr(2, 0);

        // dp[n][0] = dp[n][1] = 0;  

        // two loops as 2 variables n x 2
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {

                // memo code with calls changed to dp
                int profit = 0;
                if (buy) {
                    int take    = -a[i] + prev[0];
                    int notTake =  0 + prev[1]; 
                    profit = max(take, notTake);
                }
                else {
                    int take    = a[i] + prev[1]; 
                    int notTake = 0 + prev[0]; 
                    profit = max(take, notTake);
                }
                curr[buy] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
};
