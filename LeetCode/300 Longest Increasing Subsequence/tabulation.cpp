class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n+1, 0));

        for (int i = n - 1; i >= 0; i--) {              // loop for index n - 1 to 0
            for (int pi = i - 1; pi >= -1; pi--) {      // loop for prev index hence from i - 1 to -1

                // coordinate shift from memo do +1 in 2nd index of dp in each case
                int notTake = 0 + dp[i + 1][pi + 1];
                int take = 0;
                if (pi == -1 || nums[i] > nums[pi]) take = 1 + dp[i + 1][i + 1];

                dp[i][pi + 1] = max(take, notTake);    
            }
        }
        return dp[0][0];    
    }
};
