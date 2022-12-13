// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
// SPACE OPTIMISED
class Solution {
    public:
    int longestCommonSubstr (string s1, string s2, int n, int m) {
        
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // since we need only 2 rows prev and curr while forming ans so 2d to 2-1d array
        vector<int> prev(m+1, 0), curr(m+1, 0);
        int ans = 0;

        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= m; i2++) {

                if (s1[i1 - 1] == s2[i2 - 1]) {
                    curr[i2] = 1 + prev[i2 - 1];
                    ans = max(ans, curr[i2]);
                }
                else 
                    // dp[i1][i2] = 0 + max(dp[i1][i2 - 1], dp[i1 - 1][i2]);
                    curr[i2] = 0;
            }
            prev = curr;
        }
        return ans;
    }
};
/*
class Solution {
    public:
    int longestCommonSubstr (string s1, string s2, int n, int m) {
        
        
        //https://takeuforward.org/data-structure/longest-common-substring-dp-27/
        
        //LCS approach but when the chars in both str not equal we put a zero instead of max
        //since we need substring and not subarray
        //ans will be max of all values in dp array which we can calculate while making dp
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;

        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= m; i2++) {

                if (s1[i1 - 1] == s2[i2 - 1]) {
                    dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                    ans = max(ans, dp[i1][i2]);
                }
                else 
                    // dp[i1][i2] = 0 + max(dp[i1][i2 - 1], dp[i1 - 1][i2]);
                    dp[i1][i2] = 0;
            }
        }
        return ans;
    }
};*/
