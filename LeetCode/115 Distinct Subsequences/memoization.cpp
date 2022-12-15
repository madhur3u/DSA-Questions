class Solution {
public:
    /*
    https://www.youtube.com/watch?v=nVG7eTiD2bY
    https://takeuforward.org/data-structure/distinct-subsequences-dp-32/
    what we do is we compare both strings just like lcs
    but here if we matched characters s[i] and t[j] then we dont reduce both
    we make 2 calls one with i - 1 and j - 1 another with i - 1 and j
    why we are doing this is because if we remove the jth index and there is subseq afeterward
    than we wont be able to count so we take both cases call for them and return the sum

    if chars dont match just reduce the s string
    */
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {

        // base cases
        // if t string is exhausted j < 0, means subseq is found so return 1
        if (j < 0) return 1;
        // else if s string is exhausted but not the t string then return 0
        if (i < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];    // if ans for current i, j already present in dp

        // CASE 1 : char matched
        if (s[i] == t[j]) 
            //                CASE 1.1 : reducing both    CASE 1.2 : reducing only s
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        // CASE 2 : char not matched, reduce s not t
        else 
            return dp[i][j] = f(i - 1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {

        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n - 1, m - 1, s, t, dp);
    }
};
