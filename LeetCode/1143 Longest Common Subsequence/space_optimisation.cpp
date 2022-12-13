class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        // since we only req prev row saved state for curr row so spa opt from 2d -> 2 1d arrays
        vector<int> curr(n2 + 1, 0), prev(n2 + 1, 0);

        // 2 loops as 2 variables i1, i2
        for (int i1 = 1; i1 <= n1; i1++) {
            for (int i2 = 1; i2 <= n2; i2++) {

                // from memo code 2 conditions
                if (s1[i1 - 1] == s2[i2 - 1]) 
                    curr[i2] = 1 + prev[i2 - 1];
                else 
                    curr[i2] = 0 + max(curr[i2 - 1], prev[i2]);
            }
            prev = curr;
        }
        return prev[n2];  // since index shift so use n1, n2
    }
};
