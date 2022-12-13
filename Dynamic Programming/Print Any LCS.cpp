// https://leetcode.com/problems/longest-common-subsequence/description/
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i1 = 0; i1 <= n1; i1++) dp[i1][0] = 0;
        for (int i2 = 0; i2 <= n2; i2++) dp[0][i2] = 0;

        for (int i1 = 1; i1 <= n1; i1++) {
            for (int i2 = 1; i2 <= n2; i2++) {

                if (s1[i1 - 1] == s2[i2 - 1]) 
                    dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                else 
                    dp[i1][i2] = 0 + max(dp[i1][i2 - 1], dp[i1 - 1][i2]);
            }
        }
        /*
        printing LCS - print any LCS
        trace back the LCS using the 2d dp matrix
        watch video for better understanding
        https://www.youtube.com/watch?v=-zI4mrF2Pb4
        */
        string ans = "";
        int i = n1, j = n2; 

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans = s1[i - 1] + ans;
                i--;
                j--;
            }       
            else {
                if (dp[i][j - 1] > dp[i - 1][j]) j--;
                else i--;
            }   
        }
        cout<<ans;
        return dp[n1][n2];
    }
};
