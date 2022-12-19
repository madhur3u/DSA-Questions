class Solution {
public:
    int f(int i, int pi, vector<int>& nums, vector<vector<int>>& dp) {

        if (i == nums.size()) return 0;                 // base case
        if (dp[i][pi + 1] != -1) return dp[i][pi + 1];  // checking saved state

        int notTake = 0 + f(i + 1, pi, nums, dp);       // not taking curr index, prev index remains unchanged
        int take = 0;                                   // we can only take if prev was -1
        if (pi == -1 || nums[i] > nums[pi])             // or curr num > prev num
            take = 1 + f(i + 1, i, nums, dp);           // prev index will become curr i

        return dp[i][pi + 1] = max(take, notTake);      // take max of both
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        // we have 2 things for memo index i --> 0 to n - 1 and prev index pi --> -1 to n-1
        // since we cannot take -1 in array index so we shift coordinate by 1 in the function
        // we save states by doing pi + 1
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, dp);
    }
};
