// https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        // setting left and right pointers
        // we set right pinter k distance away fron end to handle edge cases
        // as we compare arr[mid + k] so we want we should always have k elements to the right
        int l = 0, r = size(arr) - k;
        
        // binary search to find window
        // mid to [mid + k - 1] will denote current window
        // we need to check if to its left or right better values present
        while (l < r){
            int mid = (l + r) >> 1;
            
            // if the diff with k in right side is less than left we need to move window rightward
            // so update left pointer
            if (x - arr[mid] > arr[mid + k] - x)
                l = mid + 1;
            
            // else update right pointer leftwards, not mid - 1 as we may left some conditions
            // [0,2,2,3,4,6,7,8,9,9], k = 4, x = 5, DRY RUN FOR THIS CASE
            else
                r = mid;
        }
        return vector<int>(begin(arr) + l, begin(arr) + l + k);
    }
};
/*
Assume A[mid] ~ A[mid + k] is sliding window

case 1: (x - A[mid] < A[mid + k] - x), need to move window go left
-------x----A[mid]-----------------A[mid + k]----------

case 2: (x - A[mid] < A[mid + k] - x), need to move window go left again
-------A[mid]----x-----------------A[mid + k]----------

case 3: (x - A[mid] > A[mid + k] - x), need to move window go right
-------A[mid]------------------x---A[mid + k]----------

case 4: (x - A[mid] > A[mid + k] - x), need to move window go right
-------A[mid]---------------------A[mid + k]----x------
*/
