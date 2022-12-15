// https://www.youtube.com/watch?v=nVG7eTiD2bY
// https://takeuforward.org/data-structure/distinct-subsequences-dp-32/

class Solution {
public:
    int mod = 1e9 + 7;
    int numDistinct(string s, string t) {

        int n = s.size(), m = t.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 
        // we only need 1 2d array as in tabulation we are using only prev row for calculation
        // also we need only j pr j - 1th value so no need for prev array
        // we can use curr array only and make it from m to 1 in inner loop  
        // 1 indexed as we shifted index by 1 to accomodate base case
        vector<int> curr(m + 1, 0);     
        
        // base case originally was for j < 0, so we shift index by 1
        // and base case will be now for j == 0, so for j = 0, mark 1 in dp
        curr[0] = 1;

        // 2 loops as two variables i and j for s and t
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {

                // memo code with dp matrix 
                // reduce index by 1 when comparing string chars as we shifted index
                if (s[i - 1] == t[j - 1])   curr[j] = (curr[j - 1] + curr[j]) % mod;
                else                        curr[j] = curr[j];
            }
        }
        return curr[m];
    }
};
