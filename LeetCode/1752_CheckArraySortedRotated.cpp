// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// approach : if the array is rotated (not zero) then we will have 2 sorted halfes
// so there will only be one point when a[j-1]>a[j]
// and if rotated by 0 we dont have any point like that
class Solution {
public:
    bool check(vector<int>& a) {
        
        // j is the index traversing through array
        // x stores the no. of times we encounter rotation anomaly i.e. a[j-1]>a[j]
        int j = 1;
        int x = 0;
        int n = a.size();
        
        // if only one element in array
        if (n==1) return true;
        
        // traversing in array till end
        // increasing x if we found rotation 
        while (j < n){
            if (a[j-1]>a[j]) x++;
            j++;
        }
        
        // if x>1 false and if x==0 means array is sorted so true
        // now for this (x == 1 && a[0]>=a[n-1])  part, if the array is rotated then the last no. of array has to be smaller than the first no.
        // this take care of [2,1,3,4] this type of situations where x might be 1 but array is not sorted
        if ((x == 1 && a[0]>=a[n-1]) || (x == 0)) return true;
        else return false;
    }
};
