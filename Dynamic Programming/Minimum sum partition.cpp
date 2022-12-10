// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
class Solution {
  public:
	int minDifference(int arr[], int n)  { 
	    
	    // k stores total sum of all elements of arr
	    int k = 0;
	    for (int i = 0; i < n; i++) k += arr[i];
	    
	    // this code is same as subset sum k, k here is totalSum, we take the most eff code here
	    // https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
	    // https://github.com/madhur3u/DSA-Questions/tree/main/Dynamic%20Programming/Subset%20Sum%20Problem
	    vector<bool> prev(k+1, 0), curr(k+1, 0);
        prev[0] = curr[0] = true;

        if (arr[0] <= k) prev[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= k; target++) {
                
                bool notTake = prev[target]; 
                bool take = false;
                if (arr[i] <= target) take = prev[target - arr[i]];
                
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        // last row of 2d dp will be stored in prev arr
        // cells marked as true will be all sums which are possible by some subsets
        // since after half partition will repeat as p1 = i (when prev[i] true) and p2 = k - p1
        // so we need to traverse prev till half only
        int ans = 1e9;
        for (int i = 0; i <= k/2; i++) {
            if (prev[i]) {
                int p1 = i;
                int p2 = k - p1;
                ans = min(ans, abs(p2 - p1));   
            }
        }
        return ans;
	  } 
};
