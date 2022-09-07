// https://www.youtube.com/watch?v=p-OyKUgIrx4
// https://www.geeksforgeeks.org/counting-sort/

#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &a,int n){

    // finding the min and max element of the array to make our count array
    int max = *max_element(a.begin(), a.end());
    int min = *min_element(a.begin(), a.end());

    // count array of size acc to max and min
    vector<int> count (max-min+1, 0);

    // now count array will be filled with the count of the number i
    // in the index of count, index will be i - min as min no.s index will be at 0th index
    for (int i : a){
        int idx = i - min;
        count[idx]++;
    }

    // now we need to make prefix sum array of count array
    for (int i = 1; i<count.size(); i++){
        count[i] = count[i] + count[i - 1];
    }

    vector<int> ans(n, 0);

    // the prefix sum array will tell us the last index where value will be pushed in ans array
    // the value will be acc to our index
    // we traverse in reverse in our original array and place the digits in ans vector acc to count
    // we traverse in reverse so that array is stable sorted means position of same elements will be acc to original array
    for (int i = n - 1; i >= 0; i--){
        int val = a[i];
        int pos = count[val - min];
        int idx = pos - 1;
        ans[idx] = val;
        count[val - min]--;
    }

    // now fill original array with ans
    for (int i = 0; i < n; i++){
        a[i] = ans[i];
    }    
}

int main(){
    int n = 21;
    vector<int> nums = {9,6,5,7,8,2,4,3,5,6,8,7,9,8,3,-2,-10,-3,-1,-1,-1};

    // send the array and the low high index
    count_sort(nums,n);
    for (int i = 0; i<n; i++){
        cout<<nums[i]<< " ";
    }
} 
