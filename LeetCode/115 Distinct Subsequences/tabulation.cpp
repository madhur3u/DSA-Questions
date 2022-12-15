// https://www.youtube.com/watch?v=nVG7eTiD2bY
// https://takeuforward.org/data-structure/distinct-subsequences-dp-32/

class Solution {
public:
    int mod = 1e9 + 7;
    int numDistinct(string s, string t) {

        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));   // dp matrix index shifting 
        
        // base case originally was for j < 0, so we shift index by 1
        // and base case will be now for j == 0, so for all j = 0, mark 1 in dp table
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        // 2 loops as two variables i and j for s and t
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // memo code with dp matrix
                // reduce index by 1 when comparing string chars as we shifted index
                if (s[i - 1] == t[j - 1])   dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                else                        dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][m];
    }
};
