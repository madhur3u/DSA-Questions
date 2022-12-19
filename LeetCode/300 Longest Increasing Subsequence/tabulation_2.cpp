// https://takeuforward.org/data-structure/printing-longest-increasing-subsequence-dp-42/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n + 1, 1);   // we make curr ans acc to prev stored lis in dp
        int ans = 1;

        for (int i = 1; i < n; i++) {               // curr index i
            for (int pi = 0; pi < i; pi++) {        // previous index pi
                if (nums[pi] < nums[i]) 
                    dp[i] = max(dp[i], 1 + dp[pi]);
            }
            ans = max(ans, dp[i]);
        }   
        return ans;
    }
};
