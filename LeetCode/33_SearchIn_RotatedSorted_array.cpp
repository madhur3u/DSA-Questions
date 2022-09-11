// https://leetcode.com/problems/search-in-rotated-sorted-array/

/*We divide the array into parts. It is done using two pointers, low and high, and dividing the range between them by 2. 
This gives the midpoint of the range. Check if the target is present in the midpoint, calculated before, of the array. 
If not present, check if the left half of the array is sorted. 
This implies that binary search can be applied in the left half of the array provided the target lies between the value range. 
Else check into the right half of the array. Repeat the above steps until low <= high. 
If low > high, indicates we have searched array and target is not present hence return -1. 
Thus, it makes search operations less as we check range first then perform searching in possible ranges which may have target value.*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int lo = 0, hi = nums.size() - 1;
        
        while (lo <= hi){
            
            int mid = lo + (hi - lo)/2;
            
            // if target found
            if (nums[mid] == target) return mid;
            
            // checking if left half is sorted
            // if it is sorted and element is between low and mid, we update hi, else lo
            if (nums[lo] <= nums[mid]){
                if (nums[lo] <= target && target <= nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            
            // if right half is sorted
            // and element between mid and high we increase lo, else hi
            else{
                if (nums[mid] <= target && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }
};
