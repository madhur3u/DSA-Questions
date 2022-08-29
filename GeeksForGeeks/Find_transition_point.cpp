// https://practice.geeksforgeeks.org/problems/find-transition-point-1587115620/1

#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() 
{
    int n = 8;
    int a[n] = {0,0,0,0,0,1,1,1}; // {0,0,0,0} //{1,1,1} //{0,1,1,1}
    cout << transitionPoint(a, n) << endl;
    return 0;
}

// this fn find the transition point
// we use binary search here
// we need to find 1st position of 1 and return that index
// [1,1,1]     -->  in this ans is 0
// [0,0,0,0,1] -->  in this ans is 4 (first index of 1)
int transitionPoint(int a[], int n) {
    
    int low = 0;
    int high = n - 1;
    
    while (low <= high){
        
        int mid = (low + high) / 2;           // initialize mid
        
        if (a[mid] == 0) {          // if the mid element is zero increase low as we need to find 1 and array is sorted so it will be in right side
            low = mid + 1;          
        }
        else if (a[mid] == 1) {
            
            // if mid index has 1
            // 1st see if mid is 0 means 1 found in index 0 then return the mid also if 1 found elsewhere but it is preceeded by 0 then also return mid
            if (mid == 0 || (mid != 0 and a[mid - 1] == 0)){
                return mid;
            }
            
            // if none of two condition satisfy, dec high as we need 1st value of 1 which will be in left side
            high = mid - 1;
        }
    }
    return -1;                  // if tr point never found return -1
}
