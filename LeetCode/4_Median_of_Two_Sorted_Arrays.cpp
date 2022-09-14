// https://leetcode.com/problems/median-of-two-sorted-arrays/
// https://www.youtube.com/watch?v=NTop3VTjmxk
// https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/
// PLEASE PLEASE DRY RUN

/*
Algorithm:

    Initialize variables : l=0 and r=n (size of smaller array)
    Iterate till condition l<=r evaluates to be true
    Make a partition at the middle of the range and pick up the elements before the partition from first array (say cut1).
    Now take the remaining elements from the second array (say cut2).
    Find the values of border elements of the range of elements taken from both the arrays:

    Aleft=leftmost element taken from first array
    Bleft=leftmost element taken from second array
    Aright=rightmost element taken from first array
    Bright=rightmost element taken from second array

    Now compare the cross elements to ensure sorting order of the elements (l1<=r2 && l2 <=r1). If condition evaluates to be true and 
    total number of elements in both the arrays is even then median =(max(l1, l2) +min(r1, r2))/2 else, median = max(l1, l2)
    If l1>r2 then reduce right limit to cut1-1
    Else, increament left limit to cut1+1

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        int m = B.size();
        
        if (n > m)
            return findMedianSortedArrays(B, A);
        
        int l = 0, r = n;
        
        while (l <= r){
            
            int cut1 = (l + r) >> 1;
            int cut2 = (n + m + 1)/2 - cut1;
            
            int Aleft   = (cut1 == 0) ? INT_MIN : A[cut1 - 1];
            int Aright  = (cut1 == n) ? INT_MAX : A[cut1];
            
            int Bleft   = (cut2 == 0) ? INT_MIN : B[cut2 - 1];
            int Bright  = (cut2 == m) ? INT_MAX : B[cut2];
            
            // when our partition is correct
            if (Aleft <= Bright && Bleft <= Aright){
                
                // for odd total
                if ((n + m) % 2) return max(Aleft, Bleft);
                // for even
                return (max(Aleft, Bleft) + min(Aright, Bright))/2.0;
            }
            else if (Aleft > Bright) r = cut1 - 1;
            else l = cut1 + 1;
        }
        return -1;
    }
};
