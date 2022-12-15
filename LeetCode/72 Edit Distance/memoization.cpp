class Solution {
public:
    /*
    we place two pointers i and j at both strings end and compare them using all possibilites

    s1 = h o r s e
    s2 = r o s

    CASE 1 : chars at i and j match
    we dont need to do anything as char match so we will keep it in s1 so no task performed
    jut reduce both index and check for remaining characters

    CASE 2 : char not matched --> we have 3 possibilities
    we will take all 3 and minimise the ans

    1. Deleting --> s1 = h o r s ()        s2 = r o (s)
    deleting will be performed in s1 only and index will be reduced, nothing to be done in s2
    (i - 1, j)

    2. Insert   --> s1 = h o r s (e) s     s2 = r o (s)
    in above case s is inserted in s1 in end and it matched with s from s2
    so we reduce j as we made  match, but i remains same as we inserted after i 
    so we still need i as it can match with some other character in future ans it was not used here
    (i, j - 1)

    3. Replacing --> s1 = h o r s (s)       s2 = r o (s)
    e replaced with s, both s matched so reduce both index
    (i - 1, j - 1)

    take min of all 3 cases and return

    BASE CASE FORMATION :

    CASE 1 : s1 is over and some chars of s2 are left
    so to covert s1 to s2 we need to insert remaining char of s2 in s1 which is empty
    so we need to push j + 1 character from s2 in s1
    return j + 1

    CASE 2 : s2 over s1 has char
    we found string but some are still left in s1, delete them 
    return i + 1  i.e. no. of chars to delete 
    */
    int f(int i, int j, string s1, string s2, vector<vector<int>>& dp) {

        // BASE CASES
        if (i < 0) return j + 1;    // case 1
        if (j < 0) return i + 1;    // case 2

        if (dp[i][j] != -1) return dp[i][j];

        // CASE 1
        if (s1[i] == s2[j]) return dp[i][j] = 0 + f(i - 1, j - 1, s1, s2, dp);

        // CASE 2
        int del = 1 + f(i - 1, j, s1, s2, dp);      // deleteing char form s1
        int ins = 1 + f(i, j - 1, s1, s2, dp);      // inserting char in s1
        int rep = 1 + f(i - 1, j - 1, s1, s2, dp);  // replacing char in s1[i] with s2[j]

        return dp[i][j] = min(del, min(ins, rep));
    }
    int minDistance(string s1, string s2) {
        
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s1, s2, dp);
    }
};
