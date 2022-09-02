// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    
    // this fn swap two nos. pass by pointers 
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    // solution
    void sortColors(vector<int>& a) {
        
        // initializing two pointers at start and ending point of array
        int n = a.size();
        int i = 0, j = n - 1;
        
        // in the first loop we push all zero to end
        // we find non 2 no. from right side and 2 from left side
        // and swap them so that all 2s are placed at end
        while (i<j){ 
            while (i<n && a[i] != 2) i++;
            while (j>0 &&a[j] == 2) j--;
            if (i < j){
                swap(&a[i], &a[j]);
                i++;
                j--;
            }
        }
        
        // initializing pointers again at atart and end
        i = 0; j = n - 1;
        
        // this loop place all zero to front of array
        // since 2 is aleady sorted so this will sort our array of 0 1 2
        while (i<j){          
            while (i<n && a[i] == 0) i++;
            while (j > 0 && a[j] >= 1) j--;
            if (i < j){
                swap(&a[i], &a[j]);
                i++;
                j--;
            }
        }  
    }
};
