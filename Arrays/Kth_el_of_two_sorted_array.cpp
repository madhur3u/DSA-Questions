// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// read MERGING TWO ARRAY FIRST USING GAP METHOD  --> https://github.com/madhur3u/DSA-Questions/blob/main/Arrays/Merge_without_extra _space.cpp

// after both array has been sorted, we just need to find the value at kth index

class Solution{
    public:
    int kthElement(int a1[], int a2[], int n, int m, int k){
        
        // gap method sorting starts here
        int gap = ceil(float(n+ m)/2);
        
        while (gap > 0){
            int i = 0, j = gap;
            
            while (j < (n + m)){
                
                if (j < n && a1[i] > a1[j]) swap(a1[i], a1[j]);
                else if (i < n && j >= n && a1[i] > a2[j - n]) swap(a1[i], a2[j - n]);
                else if (i >= n && j >= n && a2[i - n] > a2[j - n]) swap(a2[i - n], a2[j - n]);
                
                i++, j++;
            }
            if (gap > 1) gap = ceil(float(gap)/2);
            else gap = 0;
        }
        // gap method sorting ends here
        
        // now both array if put together are sorted 
        // so we need to find if k exist in 1st array or 2nd and return value at that index
        // k is one based index
        if (k <= n) return a1[k - 1];
        else return a2[k - n - 1];
    }
};
