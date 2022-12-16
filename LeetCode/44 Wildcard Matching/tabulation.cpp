class Solution {
public:
    // this fn check if in string p from index [0, j] all are '*' or not
    bool checkAllStars(string& p, int j) {
        while (j >= 0) if (p[j--] != '*') return false;
        return true;
    }
    bool isMatch(string s, string p) {

        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        /*  BASE CASES
        since base case in memo code are when i and j rech negetive
        so we shift index right by 1 so base case become == 0
        and i and j will be 1 indexed now for the string

        if (i == 0 && j == 0)  return true;                       // both over
        if (j == 0 && i > 0)   return false;                      // p over not s
        if (i == 0 && j > 0)   return checkAllStars(p, j - 1);    // s over not p
        */
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) dp[i][0] = false;
        for (int j = 1; j <= m; j++) dp[0][j] = checkAllStars(p, j - 1);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // CASE 1
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') 
                    dp[i][j] = dp[i - 1][j - 1];

                // CASE 2
                else if (p[j - 1] == '*') 
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];

                // CASE 3
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};
