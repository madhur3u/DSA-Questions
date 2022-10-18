/*
https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/
Using Quickselect Algorithm

    Choose any random element as PIVOT.
    Use Partition Algorithm to partition the given array into 2 parts and place the PIVOT at its correct position ( called as index ).
    Partition Algorithm : All the elements are compared to the PIVOT, and the elements less than the PIVOT are shifted towards the 
    left side of the array and greater are shifted toward the right side of the array.
    Now since, all elements right to the PIVOT are greater and left to the PIVOT are smaller , compare index with N-k ( where N = size of array )  
    and recursively find the part to find the Kth largest element.
    The worst case time complexity of this method is O(n^2) but its Average time complexity is O(n).
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // choosing pivot
        int l = 0, r = nums.size() - 1, ans;
        while (true) {
            
            // placing pivot in its sorte position
            int idx = partition(nums, l, r);

            // if pivot is in the kth index from start, we are sorting array in reverse else n - k to be used 
            if (idx == k - 1) {
                ans = nums[idx];
                break;
            }
            // update pivot for next if not found
            else if (idx > k - 1) r = idx - 1;
            else if (idx < k - 1) l = idx + 1;
        }
        return ans;
    }

    // this place the pivot in reverse sorted position 
    // READ QUICK SORT
    int partition(vector<int>& a, int left, int right) {

        int pivot = a[left];
        int l = left + 1;
        int r = right;

        while (l <= r) {

            if (a[l] < pivot && a[r] > pivot) {
                swap(a[l], a[r]);
                l++, r--;
            }
            if (a[l] >= pivot) l++;
            if (a[r] <= pivot) r--;
        }
        swap(a[left], a[r]);
        return r;
    }
};
