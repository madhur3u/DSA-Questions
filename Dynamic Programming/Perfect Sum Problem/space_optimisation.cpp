// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
class Solution{
	public:
	int perfectSum(int nums[], int n, int k) {
	    vector<int> prev(k+1), curr(k+1);   // since we use only prev row to calculate new row so 2d -> 1d
        
        /* forming dp with base cases
        if (index == 0) {
            if (nums[0] == 0 && sum == 0) return 2;     // case 1
            if (sum == 0) return 1;                     // case 2
            if (sum == nums[0]) return 1;               // case 3    
            return 0;                                   // subset with sum not found return 0
        }
        */
        if (nums[0] <= k) prev[nums[0]] = 1;   // case 3
        if (nums[0] == 0) prev[0] = 2;         // case 1
        else              prev[0] = 1;         // case 2
        
        // index traverse from 1 to n, as we already took 0th row case in base case
        // sum from 0 to n
        for (int index = 1; index < n; index++) {
            for (int sum = 0; sum <= k; sum++) {
                
                int notTake = prev[sum];
                int take = 0;
                if (nums[index] <= sum) take = prev[sum - nums[index]];
                
                curr[sum] = (take + notTake) % (int)(1e9 + 7);
            }
            prev = curr;
        }
        return prev[k];
	  }
};
