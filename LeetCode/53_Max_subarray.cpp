// https://leetcode.com/problems/maximum-subarray/
// KADANE'S ALGORITHM

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // current sum hold the current subarray sum
        // max sum holds the ans initialize with min of int
        int current_sum = 0;
        int max_sum = INT_MIN;
        
        for (int i : nums){
            
            // if current sum is less than 0 
            // we mke it zero because we do not need negetive value
            // to compute next subarray sum as it will reduce our sum
            if (current_sum < 0) current_sum = 0;
            
            // inc the current sum
            // compare with max sum
            current_sum += i;
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
        
    }
};
