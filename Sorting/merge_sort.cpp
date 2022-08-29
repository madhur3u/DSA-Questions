// https://www.geeksforgeeks.org/merge-sort/
// https://takeuforward.org/data-structure/merge-sort-algorithm/

#include <bits/stdc++.h>
using namespace std;

// this fn merge the small blocks to form sorted big block
// it takes both portion from low to mid and mid + 1 to high
// compare each element using two pointers i and j
// and put it in a temp array b sorted 
// after whole sort done put the elements of b in original array a
void merge(int a[], int low, int mid, int high){
    
    // temp array b k control b array
    int b[high-low+1];
    int k = 0;
    
    // i and j are the two starting pointers of both blocks to be merged
    int i = low, j = mid+1;
    
    // while none of block is used up
    // normal algo just check for values and put smaller value first
    while (i <= mid && j<=high){
        if (a[i] < a[j])    b[k++] = a[i++];
        else                b[k++] = a[j++];     
    }
    
    // there might be possibility that one block has some element left to be inserted
    // so we check for that if pointers have reached outside or not
    // if not put all elements from that block in temp b array
    while (i<=mid){
        b[k++] = a[i++];
    }
    while (j<=high){
        b[k++] = a[j++];
    }
    
    // putting elements from temp array in original array a
    // a start from low to high as we getting in fn parameters
    for(i = 0, k = low; k<=high; k++){
        a[k] = b[i++];
    }
}

// function to sort the array
// using recursion we divide array into half parts in each recursion
// till the array is divided into only one element
// after that from those single block we merge it into the array while sorting
void mergeSort(int a[],int low, int high){

    if (low < high){
        
        // mid is the point till which we divide 1st half
        // then after that second half
        int mid = (low + high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        
        // merge both parts while sorting
        merge(a, low, mid, high);
    }
    
}

int main(){
    int nums[] = {7,58,3,41,2,1,9,5};
    int n = 8;

    // send the array and the low high index
    mergeSort(nums,0, n-1);
    for (int i = 0; i<n; i++){
        cout<<nums[i]<< " ";
    }
} 
