// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s

// all rows are sorted and we need to find row with max 1s
// logic behind this is we traverse from last index of 1st row and move left till encounter a zero
// so  j = m and we check leftwards
// also update answer which holds the row with max no. of 1
// for next iteration we check for leftward to the point till we have checked in last row
// so it will not go in loop till we encounter a row with more no. of 1s so ans will be safe
// finally return the ans

// O(N+M) n as for loop amd m as we go leftwards so never in same index twice

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  
	int rowWithMax1s(vector<vector<int>> a, int n, int m) {
	    
        // initializing j the index which will traverse leftwards and ans which holds row no.
	    int j = m;
	    int ans = -1;
	    
        // traverse in each row using for loop
	    for (int i = 0; i<n; i++){
	        
            // condition for going into the loop is if we find a 1 leftwards to the previous position 
            // and also in j is in range if yes then we update ans and shift towards j left
            // j = m a index more than max so checking left to a row is easy using j - 1
	        while ((j-1)>=0 && a[i][j-1] == 1){
	            ans = i;
	            j--;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
