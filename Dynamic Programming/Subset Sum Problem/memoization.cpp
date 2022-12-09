// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// RECURSIVE SOLN
// Normal rec coln is simple just take and not take
// since we have 2 variables in each call index and k so for memo make 2d array dp[i][k + 1]
class Solution{   
public:
    bool dfs(int i, vector<int>& arr, int k, vector<vector<int>>& dp) {
        
        // BASE CASES
        if (k == 0) return true;                // sum found as target reach 0       
        if (k < 0)  return false;               // if k < 0 means we have subtracted more, no -ve nos so false
        if (i == 0) return arr[0] == k;         // if we at last index 0, k should be equal to arr[0] for true
        if (dp[i][k] != -1) return dp[i][k];    // if state already saved for i, k+1 pair return that
        
        bool take = dfs(i - 1, arr, k - arr[i], dp);    // taking curr el into cons, subtract it from k
        bool notTake = dfs(i - 1, arr, k, dp);          // not taking
        
        return dp[i][k] = take || notTake;      // return || of both cases and save in dp
    }
    bool isSubsetSum(vector<int>arr, int k){
        
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return dfs(n - 1, arr, k, dp);
    }
};
