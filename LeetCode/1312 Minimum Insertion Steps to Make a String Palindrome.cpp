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
    let s = 'bbcbcb'ca'b' --> highlighted one is the longest palindrome --> bbcbcbb
    if we reverse s then, t = 'b'ac'bcbcbb' 
    so in t if we see the longest palindrome remains same --> bbcbcbb

    so if we see observe in both s and t longest palindrome is LCS in both s and t
    so we do that exactly

    now to find no. of insertins we needed to make s a palindrome
    for that we need to add all those chars which are not part of our palindrome to oppposite side
    so count no. of characters not in palindrome
    so we count n - characters in palindrome which will be our answer

    In order to minimize the insertions, we need to find the length of the longest palindromic 
    component or in other words, the longest palindromic subsequence.

    Minimum Insertion required = n(length of the string) – length of longest palindromic subsequence.
    */
    int minInsertions(string s) {
        
        string t = s;
        reverse(t.begin(), t.end());
        return s.size() - lcs(t, s);
    }
};
