// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        // profit will hold value of max profit achievable
        int profit = 0;
        
        // left pointer as buy, right pointer as sell
        int buy = 0, sell = 0;
        
        // traverse till right pointer is out of array
        while (sell < a.size()){
            
            // we will have profit when it is >0
            // so updating profit if sell-buy > 0
            if (a[sell] - a[buy] > 0) 
                profit = max(profit, a[sell] - a[buy]);
            
            // if we are getting -ve or 0 profit
            // we can update our left index all the way to right
            // as we need the lowest point at which we will buy
            else 
                buy = sell;
            
            // right pointer will always increment
            // to compute next profits
            sell++;
        }
        return profit;
    }
};
