// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        // ans as n + 1 as maximum subarray length can be n
        int ans = n + 1;
        
        // will use 2 pointers sliding window method
        // place the initial left pointer i at 0
        int i = 0;
        
        // this will hold the current window sum i - j
        int current_sum = 0;
        
        // right pointer of window j will inc in each iteration
        for (int j = 0; j < n; j++){
            
            // compute the sum for current window
            current_sum += nums[j];
            
            // check if sum >= target
            // run this loop till condition true and compute ans at each step
            // also decrease the window width and sum 
            while (current_sum >= target){
                
                ans = min(ans, j - i + 1);
                current_sum -= nums[i++];
            }
        }
        // return ans, % n+1 for the case when ans has to be zero means no subarray found
        return ans % (n+1);
    }
};
