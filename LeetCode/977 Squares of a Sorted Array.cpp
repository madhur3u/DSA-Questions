/*
-4 -1 0 3 10
 |         |
 l         r

keeping two pointers at extremes initially and check whose abs value is greater
the one whch is greater will have > square so we push that value to end of our ans array and inc/dec the pointer
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> res(nums.size());

        // idx for index of res vector and l and r are the two pointers 
        int idx = nums.size() - 1;
        int l = 0, r = nums.size() - 1;

        // traverse till l and r cross each other
        while (l <= r) {

            // if left abs is > right, push left square else push right square
            // dec index for next num
            if (abs(nums[l]) > abs(nums[r])) {
                res[idx--] = nums[l] * nums[l];
                l++; 
            }
            else {
                res[idx--] = nums[r] * nums[r];
                r--;
            }
        }
        return res;
    }
};
