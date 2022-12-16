class Solution {
public:
    // this fn check if in string p from index [0, j] all are '*' or not
    bool checkAllStars(string& p, int j) {
        while (j >= 0) if (p[j--] != '*') return false;
        return true;
    }
    bool isMatch(string s, string p) {

        int n = s.size(), m = p.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // since we need only 2 rows prev and curr row so 2d dp to 2 1d dp
        vector<bool> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = true;         
        for (int j = 1; j <= m; j++) prev[j] = checkAllStars(p, j - 1);     

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // CASE 1
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') 
                    curr[j] = prev[j - 1];

                // CASE 2
                else if (p[j - 1] == '*') 
                    curr[j] = curr[j - 1] | prev[j];

                // CASE 3
                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};
