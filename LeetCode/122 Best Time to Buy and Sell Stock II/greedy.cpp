class Solution {
public:
    /*
    The profit is the sum of sub-profits
    we try to buy stock at each a[i]
    and if we get a +ve profit by selling it in next iteration we add it up
    else we have loss so we buy here rather than at prev
    we buy irrespective of we had profit at curr i

    add up all profit

    DRY RUN :
    [7,1,5,3,6,4]

    buy at 7 first i at 1, compared with 1 -ve profit so profit = 0, buy = 1
    i at 5, profit = 0 + 4, buy = 5
    i at 3, -ve profit so profit remains 4 and buy = 3
    i at 6, profit = 3 + 4, buy = 6
    i at 4, -ve profit so profit remains 7 and buy 4

    last index so return accumulated profit = 7

    from above we can also conclude that buy == a[i - 1], no need of extra variable
    */
    int maxProfit(vector<int>& a) {
        
        int n = a.size();
        int profit = 0;       
        
        for (int i = 1; i < n; i++) {
            profit += max(0, a[i] - a[i - 1]);
        }
        return profit;
    }
};
