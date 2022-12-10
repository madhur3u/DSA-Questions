// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
class Solution {
	public:
	  int generate_subsets(int index, int sum, int nums[], vector<vector<int>>& dp){
        
        // BASE CASES --> we check subsets at i == 0 as we will have all comb after take / non take 
        // case 1 : sum == 0, means we found a subset with given sum but if curr el nums[0] == 0
        // it means that we can have one more subset with same sum as adding 0 no effect so we return 2
        // case 2 : sum is 0 but oth el not zero so only 1 subset return 1
        // case 3 : sum == 0th element, means when we subtract it, sum become 0 so 1 subset return 1
        if (index == 0) {
            if (nums[0] == 0 && sum == 0) return 2;     // case 1
            if (sum == 0) return 1;                     // case 2
            if (sum == nums[0]) return 1;               // case 3    
            return 0;                                   // subset with sum not found return 0
        }
        if (dp[index][sum] != -1) return dp[index][sum];    // if state already saved return from dp
        
        // not taking curr el into consideration 
        int notTake = generate_subsets(index - 1, sum, nums, dp);
        
        // taking curr el, only when curr el is less than or equal to sum, we dont want sum to be -ve
        int take = 0;
        if (nums[index] <= sum) take = generate_subsets(index - 1, sum - nums[index], nums, dp);
        
        // take modulo of sum of both calls and save in dp
        return dp[index][sum] = (take + notTake) % (int)(1e9 + 7);
    }
    int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
          return generate_subsets(n - 1, sum, arr, dp);
    }
};
