// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // we take 3 variables which holds our current max product, current min producat and ans
        // set all of them to the 1st el of array
        int current_max = nums[0], current_min = nums[0];
        int max_ans = nums[0];
        
        // traverse from 1st index to end
        for (int i = 1; i < nums.size(); i++){
            
            // store the current max product in a temp variable
            // as in the next line it will get changed and we requrire its old value to calculate min product
            int temp = current_max;
            
            // current max and min will be the max and min out of the 3 
            // this will handle the zero case also as at next iteration nums[i] will get the min or max
            current_max = max({nums[i]*current_min, nums[i]*current_max, nums[i]});
            current_min = min({nums[i]*current_min, nums[i]*temp       , nums[i]});
            
            // MAX will be the max of previous one or the one we found currently
            max_ans = max(max_ans, current_max);
        }
        return max_ans;
    }
};
