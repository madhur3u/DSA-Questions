//https://www.geeksforgeeks.org/quick-sort/

#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

// this will place the pivot in its pos in sorted array array in place
// it take the 1st el as pivot
// and place all elements smaller than it to left side and larger than it to right side
int partition(int a[], int low, int high){
    
    // defining pivot and the indexes
    int pivot = a[low];
    int i = low;
    int j = high;
    
    // loop runs till index pass each other
    while (i < j){
        
        // on going left we find the element bigger than pivot
        // on going right we find the element smaller than pivot
        while (a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        
        // if i j not passed each other swap them
        // this way smaller element move to left side and larger to right side
        if (i < j) swap(&a[i], &a[j]);
    }
    
    // finally place pivot in its respective position which will be j
    // by swapping it with jth element
    swap(&a[low], &a[j]);

//     for (int i = low; i<=high; i++){
//         cout<<a[i]<< " ";
//     }
//     cout<<endl;
    
    // return pivot index
    return j;
    
}

// function to sort the array
void quickSort(int a[],int low, int high){

    if (low < high){
      
        // in this we make a pivot from which we partition our array to sort
        // the pivot we will get using parttion function which place the pivot el in its position in sorted array
        // after that we part both parts seprately to sort recursively
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot-1);
        quickSort(a, pivot+1, high);
    }
    
}

int main(){
    int nums[] = {24, 18, 38, 43, 14, 40, 1, 54};
    int n = 8;

    // send the array and the low high index
    quickSort(nums,0, n-1);
    
    for (int i = 0; i<n; i++){
        cout<<nums[i]<< " ";
    }
} 
