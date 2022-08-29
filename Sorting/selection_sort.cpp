// https://takeuforward.org/sorting/selection-sort-algorithm/
// Time Complexity: O(n^2) (nested for loops)
// Space Complexity: O(1)
// Find the minimum element in the unsorted array and swap it with the element at the beginning.
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int nums[], int n){
    
    // outer loop from 0 to n-1
    for (int i = 0; i<n-1;i++){
        
        // we are considering the 1st el to be the min and its index is in min
        int min = i;
        
        // inner loop gives us the min no. in the array from i to n index
        // inner loop from i+1 as we have already taken i index no. in min
        // update min index if smaller number found
        for (int j = i+1; j<n; j++){
            if (nums[j]<nums[min]) min = j;
        }
        
        // swap the no. at ith index with the no. at min index
        int temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }
}

int main(){
    // array to be sorted
    int nums[] = {7,58,3,41,2,1,9,54};
    int n = 8;
  
    selectionSort(nums, n);

    for (int i = 0; i<n; i++){
        cout<<nums[i]<< " ";
    }
} 
