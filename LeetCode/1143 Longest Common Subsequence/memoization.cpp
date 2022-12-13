class Solution {
public:
    int f(int i1, int i2, string& s1, string& s2, vector<vector<int>>& dp) {

        if (i1 < 0 || i2 < 0) return 0; // base case
        if (dp[i1][i2] != -1) return dp[i1][i2];

        // if both index have equal element inc size of lcs by 1 and reduce both index for next call
        if (s1[i1] == s2[i2]) return dp[i1][i2] = 1 + f(i1 - 1, i2 - 1, s1, s2, dp);

        // else we have to take both case 
        // reduce 1st index in one case
        // reduce 2nd index in 2nd case
        // take max of both and return that
        else {
            return dp[i1][i2] = 0 + max(f(i1, i2 - 1, s1, s2, dp), f(i1 - 1, i2, s1, s2, dp));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return f(n1 - 1, n2 - 1, s1, s2, dp);
    }
};
