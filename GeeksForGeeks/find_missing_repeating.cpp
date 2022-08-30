//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        vector<int> v(n+1, 0);
        int *a = new int[2];
        
      // create vector to store count of each value
        for (int i = 0; i<n;i++){
            v[arr[i]]++;
        }
      
      // if count 2 repeating
      // if count 0 missing
        for (int i = 1; i<n+1;i++){
            // cout << v[i] << endl;
            if (v[i] == 2) a[0] = i;
            if (v[i] == 0) a[1] = i;
        }
        return a;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
