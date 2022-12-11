class Solution {
public:
    int f(int i, int sum, vector<int>& coins, vector<vector<int>>& dp) {

        // BASE CASES
        if (i == 0) {
            // this is the last coin so we will take all if it can make sum 0
            // so check if sum can get 0 by % with coin[i]
            // if yes we return no. of coins i.e. sum / coins[i]
            // else return big number 1e9 as we minimise ans this wont be taken
            if (sum % coins[i] == 0) return sum / coins[i];
            return 1e9;
        }
        if (dp[i][sum] != -1) return dp[i][sum];    // if already calculated stored in dp

        // not take case we reduce index rest all same
        int notTake = 0 + f(i - 1, sum, coins, dp);

        // take case initial 1e9, we can only take if denomination is less than or equal to sum
        // so check it first and then add 1 call dfs, since we can take it multiple times
        // so we dont reduce index we reduce sum only
        int take = 1e9;
        if (sum >= coins[i]) take = 1 + f(i, sum - coins[i], coins, dp);

        // save curr state in dp and return
        return dp[i][sum] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n - 1, amount, coins, dp);

        // if ans >= 1e9 means we cannot form sum with given coins so return -1 else the ans
        return (ans >= 1e9) ? -1 : ans;
    }
};
