// https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& nums) {
        
        /* we need to find two subsets such that diff od thier sum == d
        let sum of 1st subset be se and 2nd s2
        so s1 - s2 = d is what we need
        
        also s1 + s2 = totalSum (sum of all elements of array)
        so s1 = totalSum - s2, putting this in 1st eq
        
        totalSum - s2 - s2 = d
        therefore s2 = (totalSum - d)/2
        
        so question is reduced to finding no of subsets with sum == (totalSum - d)/2
        */
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int k = (totalSum - d)/2;
        
        // we need to make sure k is +ve else there wont be any subset return 0
        // also (totalSum - d) should be an even number else we can divide by 2 and find subset as all no. are integers in nums
        if ((totalSum - d) % 2 == 1 || k < 0) return 0;
        
        // now we need to find no. of subsets with sum == k, already done that
        // using most eff code here
        // https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
        
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
