/*
Time Complexity: O(n * 2) --> O(n)
Reason: There are two nested loops that account for O(N*2) complexity

Space Complexity: O(6) --> O(1)
Reason: We are using an 3 array of size ‘2’.
*/
class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int n = a.size();
        // store in 3 rows as we need 2 next rows and one curr row
        vector<int> next1(2, 0), next2(2, 0), curr(2, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {

                int profit = 0;
                if (buy) {
                    int take    = -a[i] + next1[0];
                    int notTake =  0 + next1[1]; 
                    profit = max(take, notTake);
                }
                else {
                    int take    = a[i] + next2[1];   // next2 for cooldown
                    int notTake = 0 + next1[0]; 
                    profit = max(take, notTake);
                }
                curr[buy] = profit;
            }
            next2 = next1;
            next1 = curr;
        }
        return curr[1];
    }
};

/*
122. Best Time to Buy and Sell Stock II
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
same as above problem
we just cant buy next day we sold a stock so in take of sell change index from i + 1 to i + 2

RECURSIVE - MEMO SOLUTION

class Solution {
public:
    int f(int i, int buy, vector<int>& a, vector<vector<int>>& dp) {

        if (i >= a.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if (buy) {
            int take = -a[i] + f(i + 1, 0, a,dp); 
            int notTake =  0 + f(i + 1, 1, a,dp); 
            profit = max(take, notTake);
        }
        else {
            int take = a[i] + f(i + 2, 1, a,dp); 
            int notTake = 0 + f(i + 1, 0, a,dp); 
            profit = max(take, notTake);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& a) {
        
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, a, dp);
    }
};*/
