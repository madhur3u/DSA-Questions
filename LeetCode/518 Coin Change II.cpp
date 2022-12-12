class Solution {
public:
    // same as coin change code insted of returning min we add up both calls
    // in base case we store 1 if possible 0 if not possible
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        // we need atmost 2 rows i-1th row and ith row so 2d dp to 1d dp
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for (int sum = 0; sum <= amount; sum++){
            if (sum % coins[0] == 0) prev[sum] = 1;
            else prev[sum] = 0;
        }
        // 2 loops as we have 2 changing indices i and sum in memo code
        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= amount; sum++) {

                // memo code with calls changed to dp
                int notTake = prev[sum];
                int take = 0;
                if (sum >= coins[i]) take = curr[sum - coins[i]];

                curr[sum] = (take + notTake);
            }
            prev = curr;
        }
        return prev[amount];
    }
};
/*T = amount
Time Complexity: O(N*T)
Reason: There are two nested loops.

Space Complexity: O(T)
Reason: We are using an external array of size ‘T+1’ to store two rows only.*/
