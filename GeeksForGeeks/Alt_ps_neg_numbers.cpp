// https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
/*
Input: 
N = 10
Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
Output:
5 -5 2 -2 4 -8 7 1 8 0 
Explanation : Positive elements : 5,2,4,7,1,8,0
Negative elements : -5,-2,-8
As we need to maintain the relative order of
postive elements and negative elements we will pick
each element from the positive and negative and will
store them. If any of the positive and negative numbers
are completed. we will continue with the remaining signed
elements.The output is 5,-5,2,-2,4,-8,7,1,8,0.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int a[], int n) {
	    // code here
	    
    // first we make 2 diff vectors to store pos and neg numbers
    // iterate through array and store values in vectors\
    // n time n space
	    vector<int> pn;
	    vector<int> nn;
	    
	    for (int i = 0; i<n; i++){
	        if (a[i]>=0) pn.push_back(a[i]);
	        else         nn.push_back(a[i]);
	    }
	    
    // now we will alternatively add pos no and neg no. in the original array
    // if one of the vector empty all elements for other vector added simultaneously
	    int i = 0, j = 0, k = 0;
	    while (i<n){
	        if (j < pn.size()) a[i++] = pn[j++];
	        if (k < nn.size() && i<n) a[i++] = nn[k++];
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
