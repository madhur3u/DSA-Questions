// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        
        // ALL BASE CASES
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;
        
        // using binary search to find the peak
        // lo and hi as 2nd and 2nd last element 
        int lo = 1;
        int hi = n - 2;
        
        while (lo <= hi){
            
            int mid = lo + (hi - lo)/2;
            
            // if the current mid is peak element we return that
            if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) 
                return mid;
            
            // if the peak is on the left side means the elment to left of mid is > mid el
            // that means we need to find the peak in left half, so update the hi
            else if (nums[mid-1] > nums[mid])
                hi = mid - 1;
            
            // same way if peak on right side, update lo
            else
                lo = mid + 1;
        }
        return -1;
    }
};
