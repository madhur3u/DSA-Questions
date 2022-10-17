/*
We calculate all the subarrays with atmost sum goal. 
Then subtract no. of subarrays with atmost sum goal-1. 
Subtract and we have subarrays of only sum goal.
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      
        // calling fn 2 times for goal and goal - 1
        return atMostKSum(nums, goal) - atMostKSum(nums, goal - 1);
    }
    // calculating total number of subarrays with at most K sum
    int atMostKSum(vector<int>& nums, int k) {

        // if sum needed < 0 return 0, as no neg numbers
        if (k < 0) return 0;
        int res = 0;

        // sliding window using 2 pointers left and right
        for (int l = 0, r = 0; r < nums.size(); r++) {

            // subtract the current element from k, if 1 will decrease our k else remains same
            k = k - nums[r];

            // case when we have more than k 1's in our subarray
            // we dec our window length from left and inc k
            while (k < 0) {
                k = k + nums[l];
                l++;
            }
            // when we are here we are at a valid subarray
            // add all subaray within that to our answer
            res += (r - l + 1);
        }
        return res;
    }
};
