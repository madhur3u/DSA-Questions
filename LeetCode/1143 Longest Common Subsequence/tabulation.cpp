class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // forming 1st row from base case
        // SHIFTING THE INDEX sincew ego to i1 == i2 == -1 in base case
        // so we shift index by 1 in our dp array and hold 0 in 0th index
        // so we do i1 - 1, i2 - 1 to access strings curr element for given i1, i2 
        // and i1 - 1, i2 - 1 to access dp prev row elements 
        for (int i1 = 0; i1 <= n1; i1++) dp[i1][0] = 0;
        for (int i2 = 0; i2 <= n2; i2++) dp[0][i2] = 0;

        // 2 loops as 2 variables i1, i2
        for (int i1 = 1; i1 <= n1; i1++) {
            for (int i2 = 1; i2 <= n2; i2++) {

                // from memo code 2 conditions
                if (s1[i1 - 1] == s2[i2 - 1]) 
                    dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                else 
                    dp[i1][i2] = 0 + max(dp[i1][i2 - 1], dp[i1 - 1][i2]);
            }
        }
        return dp[n1][n2];  // since index shift so use n1, n2
    }
};
