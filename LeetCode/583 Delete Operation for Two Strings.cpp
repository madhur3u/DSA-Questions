class Solution {
public:
    // most eff code to find length of LCS
    // https://leetcode.com/problems/longest-common-subsequence/description/
    int lcs(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<int> curr(n2 + 1, 0), prev(n2 + 1, 0);

        for (int i1 = 1; i1 <= n1; i1++) {
            for (int i2 = 1; i2 <= n2; i2++) {
                if (s1[i1 - 1] == s2[i2 - 1]) 
                    curr[i2] = 1 + prev[i2 - 1];
                else 
                    curr[i2] = 0 + max(curr[i2 - 1], prev[i2]);
            }
            prev = curr;
        }
        return prev[n2]; 
    }
    /*
    To minimize the operations, we will first try to refrain from deleting those characters which are 
    already present in str2. More extensively, we refrain from deleting those characters which are 
    common and come in the same order. To minimize the operations, we would like to keep the maximum 
    common characters coming in the same order intact. These maximum characters are the characters of 
    the longest common subsequence. 

    In order to minimize the operations, we need to find the length of the longest common subsequence.
    Minimum Operations required = (n – k) + (m – k) --> n + m - 2*k -- k == LCS size
    */
    int minDistance(string word1, string word2) {
        
        int LCS = lcs(word1, word2);
        return word1.size() + word2.size() - 2*LCS;
    }
};
