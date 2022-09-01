//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // sum will hold the value of current window sum
        // maxc holds answer which is the max subarray length
        int sum = 0, maxc = 0;
        
        // pointers set at initial values and will control the length of the sliding window
        int i = 0, j = 0;
        
        // loop till i is in range
        while (i<n){
            
            // this will shift our window rightwards by adding j++
            // before that it will check if the sum of that window is within k
            // if > k the sum, then loop ends or if j go out of range
            while ((j<n) && (sum + a[j])<=k){
                sum += a[j];
                j++;
            }
            // cout<<j<<" "<<i<<endl;
            
            // this will check the current window sum if its equal to k 
            // it updates the max count of subarray
            if (sum == k){
                maxc = max(maxc, j-i);
            }
            
            // decrease the window from front by i++
            // and also reduce the value from sum of window
            sum -= a[i];
            i++;
        }
        return maxc;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
