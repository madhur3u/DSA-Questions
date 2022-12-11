class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // we need atmost 2 rows i-1th row and ith row so 2d dp to 1d dp
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        /* forming base cases
        if (i == 0) {
            if (sum % coins[i] == 0) return sum / coins[i];
            return 1e9;
        }
        */
        for (int sum = 0; sum <= amount; sum++){
            if (sum % coins[0] == 0) prev[sum] = sum / coins[0];
            else prev[sum] = 1e9;
        }
        // 2 loops as we have 2 changing indices i and sum in memo code
        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= amount; sum++) {

                // memo code with calls changed to dp
                int notTake = 0 + prev[sum];
                int take = 1e9;
                if (sum >= coins[i]) take = 1 + curr[sum - coins[i]];

                curr[sum] = min(take, notTake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};
/*
Time Complexity: O(N*T)
Reason: There are two nested loops

Space Complexity: O(N*T)
Reason: We are using an external array of size ‘N*T’. Stack Space is eliminated.
*/
