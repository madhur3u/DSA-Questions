// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // fi, li will hold the ans initially -1
        int lo = 0, hi = nums.size() - 1;
        int fi = -1, li = -1;
        
        // finding first index at which number appear
        // we just need to update hi even when we find number
        // to search more to left to get first number
        while (lo <= hi){
            int mid = lo + (hi - lo)/2;
            if (target > nums[mid]) lo = mid + 1;
            else if (target < nums[mid]) hi = mid - 1;
            else fi = mid, hi = mid - 1;
        }
        
        lo = 0, hi = nums.size() - 1;
        
        // search totally to right
        // so inc lo even when no found
        while (lo <= hi){
            int mid = lo + (hi - lo)/2;
            if (target > nums[mid]) lo = mid + 1;
            else if (target < nums[mid]) hi = mid - 1;
            else li = mid, lo = mid + 1;
        }
        return {fi, li};
    }
};
