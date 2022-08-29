// Time Complexity: O(N^2) 
// Auxiliary Space: O(1)
// https://www.geeksforgeeks.org/insertion-sort/?ref=lbp

#include <bits/stdc++.h>
using namespace std;

// function to sort the array
void insertionSort(int nums[], int n){

    // we try to sort the left part of array in each iteration of i
    // so we have 2 parts after each iteration left sorted right unsorted
    for (int i = 1; i < n; i++){

        // the val at i is stored in a temp variable
        // we compare this value with all other elements in left side
        // if this value is not placed in sorted order we do that by swapping
        int current = nums[i];
        int j = i - 1;

        // since left part is always sorted in each it so we check till nums[j]>current
        // till the cond is satisfied we swap and make it sorted
        while (j>=0 && nums[j]>current){
            nums[j+1] = nums[j];
            j--;
        }

        // after coming out of loop the current value will be placed at
        // j + 1 position
        nums[j+1] = current;
    }   
}

int main(){
    int nums[] = {7,58,3,41,2,1,9,5};
    int n = 8;

    insertionSort(nums, n);
    for (int i = 0; i<n; i++){
        cout<<nums[i]<< " ";
    }
} 
