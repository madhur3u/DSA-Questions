// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
// https://medium.com/swlh/merge-two-sorted-arrays-without-extra-space-efficiently-o-1-gap-method-detailed-simplified-57a336146601

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) { 
            
            // initial gap value, i and j will be two pointers 
            int gap = ceil((float)(n + m)/2);
            int i, j;
            
            // run till gap = 0
            while (gap > 0){
                
                // initialise 1st pointer as 0 and 2nd as gap
                i = 0;
                j = gap;
                
                // run till j reach out of bounds
                while (j < (n + m)){
                    
                    // if both elements in 1st array
                    if (j < n && arr1[i] > arr1[j]) 
                        swap(arr1[i], arr1[j]);
                    
                    // if one element in 1st array and 2nd in 2nd array
                    else if (i < n && j >= n && arr1[i] > arr2[j - n]) 
                        swap(arr1[i], arr2[j - n]);
                     
                    // if both elements in 2nd array
                    else if (i >= n && j > n && arr2[i - n] > arr2[j - n]) 
                        swap(arr2[i - n], arr2[j - n]);
                    
                    // increase the indices
                    i++, j++;
                }
                
                // update gap
                if (gap > 1) gap = ceil((float)gap/2);
                else gap = 0;
            }
        } 
};
