// https://leetcode.com/problems/merge-sorted-array/

// we traverse both array from last and sort array in descending order and place in nums1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // i will be the last index of nums1 till where el are present
        // j will be the last index of nums2
        // k is the last index of whole n1
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        // run loop till elements are present in any of the array
        while (i >= 0 && j >= 0){
            
            // technique is same as merging two sorted arrays
            // but in descending order
            if (nums2[j] > nums1[i]){
                nums1[k--] = nums2[j--];
            }
            else nums1[k--] = nums1[i--];
        }
        
        // there might be case when elements are left in nums2
        // so we push those in nums1 from k till 0
        // this need not be checked with nums1 as it is the array in which we are placing result so it will be sorted
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};
