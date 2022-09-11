// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

/*
    The idea is the same as the previous one without duplicates.
    The only difference is that due to the existence of duplicates,
        arr[l] == arr[mid] could be possible, the first half could be out of order
        (i.e. not in the ascending order, e.g. {3, 1, 2, 3, 3, 3, 3})
        we have to deal this case separately.
        In that case, it is guaranteed that arr[high] also equal to arr[mid],
        so the condition arr[mid] == arr[l] == arr[r] can be checked before the original logic,
        if so then move left++ and right-- both towards the middle by 1 and repeat.

ALGORITHM

    Check for if target == nums[mid], if found return true.
    With duplicates we can have nums[l] == nums[r] so just update the l and r towards middle.
    If not than check for first half is that in order (i.e nums[l] <= nums[mid]
        check if target is in the range of [left, mid -1], if((nums[l] <= target) && (nums[mid] > target)) and search in it.
    if not in first half search in second half.
        Check if target is in range of [mid + 1, right], if((nums[mid] < target) && (nums[r]>= target)) and search in it.

*/

// best nlogn, worst n

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int lo = 0, hi = nums.size() - 1;
        
        while (lo <= hi){
            
            int mid = lo + (hi - lo)/2;
            
            if (nums[mid] == target) return true;
            
            // shift toward middle if both extremes el same as mid
            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]){
                lo++, hi--;
            }
            else if (nums[lo] <= nums[mid]){
                if (nums[lo] <= target && target <= nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            else {
                if (nums[mid] <= target && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return false;
    }
};
