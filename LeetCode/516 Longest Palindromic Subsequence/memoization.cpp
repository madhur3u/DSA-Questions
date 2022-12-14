class Solution {
public:
    /*
    we traverse in the string using two pointers and recursion
    keep ointers i and j initially at 0 and n - 1
    if both has equal elements we add 2, if both equal and index also equal we add 1 and no further call
    base case will be when both index pass each other i > j

    if elements not equal we take max of 2 cases 
    in 2 calls once we move left index and once we move right index
    */
    int f(int i, int j, string& s, vector<vector<int>>& dp) {

        // base case
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];    // already saved in dp

        // if equal at index i and j check index add 2 or 1 acc
        if (s[i] == s[j]) {
            if (i == j) 
                return dp[i][j] = 1;
            else 
                return dp[i][j] = 2 + f(i + 1, j - 1, s, dp);
        }
        // if not equal call for both cases and take max
        else {
            return dp[i][j] = 0 + max(f(i, j - 1, s, dp), f(i + 1, j, s, dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n - 1, s, dp);
    }
};
