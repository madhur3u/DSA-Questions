class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        /*
        base cases in memo code were whe less than 0, so right shift index by 1
        base case shift to == 0

        BASE CASES
        if (i == 0) return j;    // case 1
        if (j == 0) return i;    // case 2
        */
        for (int j = 0; j <= m; j++) dp[0][j] = j;
        for (int i = 0; i <= n; i++) dp[i][0] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // CASE 1
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = 0 + dp[i - 1][j - 1];
                
                // CASE 2
                else {
                    int del = 1 + dp[i - 1][j];      // deleteing char form s1
                    int ins = 1 + dp[i][j - 1];      // inserting char in s1
                    int rep = 1 + dp[i - 1][j - 1];  // replacing char in s1[i] with s2[j]

                    dp[i][j] = min(del, min(ins, rep));
                }
            }
        }
        return dp[n][m];
    }
};
