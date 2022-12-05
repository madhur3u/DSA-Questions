// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
class Solution{
public:	
    /*int dfs(int i, vector<int>& dp, int *arr) {
        
        if (i < 0) return 0;                // wrong case, -ve index
        if (i == 0) return arr[i];          // base case at i == 0 we take 0th el of array
        if (dp[i] != -1) return dp[i];      // if ans already saved in dp return that
        
        // 2 possb, taking ith element and forming ans from that, if we take i take i - 2 as next call
        // 2nd -> compute ans from i - 1th pos also as we can get max from there also
        int j1 = arr[i] + dfs(i - 2, dp, arr);  // pick
        int j2 = dfs(i - 1, dp, arr);           // non pick
        
        // take max of both cases
        int currMaxSum = max(j1, j2);
        return dp[i] = currMaxSum;  // store in dp and return maxSum 
    }*/
    int findMaxSum(int *arr, int n) {

        vector<int> dp(n);
        dp[0] = arr[0];     // base case

        // bottom up approach
        for (int i = 1; i < n; i++) {

            // if we pich ith element
            // we ad dp[i - 2] only when its exist
              int pick = arr[i];
              if (i > 1) pick += dp[i - 2];

              // not picking curr ith el, we pick the max already stored in dp[i - 1]
              int non_pick = dp[i - 1];

              // store max of pick and non pick in dp
              dp[i] = max(pick, non_pick);
        }

        return dp[n - 1];
    }
};
