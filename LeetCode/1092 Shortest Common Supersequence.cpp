// WATCH VIDEO AND DRY RUN
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {

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
        https://youtu.be/xElxAuBcvsU
        https://takeuforward.org/data-structure/shortest-common-supersequence-dp-31/
        making ans using dp table we get from lcs
        if both equal we take only 1 of he character

        when unequal we move either up or left in dp
        when we move left we take the j - 1th character of s2 string as we reduce s2 by 1 char on move
        when we move up we take s1[i - 1]
        */
        string ans = "";
        int i = n1, j = n2; 

        while (i > 0 && j > 0) {

            if (s1[i - 1] == s2[j - 1]) {           // equal char
                ans.push_back(s1[i - 1]);
                i--;
                j--;
            }       
            else if (dp[i][j - 1] > dp[i - 1][j]) { // moving left
                ans.push_back(s2[j - 1]);
                j--;
            }   
            else {                                  // moving up
                ans.push_back(s1[i - 1]);
                i--;
            }
        }
        // if any character left we push it in ans
        while (i > 0) { ans.push_back(s1[i - 1]); i--;}
        while (j > 0) { ans.push_back(s2[j - 1]); j--;}
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
