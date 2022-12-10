// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
class Solution{
	public:
	int perfectSum(int nums[], int n, int k) {
	    vector<vector<int>> dp(n, vector<int>(k + 1));
        
        /* forming dp with base cases
        if (index == 0) {
            if (nums[0] == 0 && sum == 0) return 2;     // case 1
            if (sum == 0) return 1;                     // case 2
            if (sum == nums[0]) return 1;               // case 3    
            return 0;                                   // subset with sum not found return 0
        }
        */
        if (nums[0] <= k) dp[0][nums[0]] = 1;   // case 3
        if (nums[0] == 0) dp[0][0] = 2;         // case 1
        else              dp[0][0] = 1;         // case 2
        
        // index traverse from 1 to n, as we already took 0th row case in base case
        // sum from 0 to n
        for (int index = 1; index < n; index++) {
            for (int sum = 0; sum <= k; sum++) {
                
                /* same as memo code
                // not taking curr el into consideration 
                int notTake = generate_subsets(index - 1, sum, nums, dp);
                
                // taking curr el, only when curr el is less than or equal to sum, we dont want sum to be -ve
                int take = 0;
                if (nums[index] <= sum) take = generate_subsets(index - 1, sum - nums[index], nums, dp);
                
                // take modulo of sum of both calls and save in dp
                return dp[index][sum] = (take + notTake) % (int)(1e9 + 7);
                */
                int notTake = dp[index - 1][sum];
                int take = 0;
                if (nums[index] <= sum) take = dp[index - 1][sum - nums[index]];
                
                dp[index][sum] = (take + notTake) % (int)(1e9 + 7);
            }
        }
        return dp[n - 1][k];
	}
};
