class Solution {
public:
    // this fn check if in string p from index [0, j] all are '*' or not
    bool checkAllStars(string& p, int j) {
        while (j >= 0) if (p[j--] != '*') return false;
        return true;
    }
    /*
    we need to compare s and p and check if can match or not acc to given criteria
    initially both index at last --> n - 1, m - 1

    CASE 1 : character match or we found a '?'
    s = a (a)       s = (a)
    p = ? (a)       p = (?)       
    in above we can see both chars match so we can reduce both 
    similiarly for 2nd a and '?', we can match ? with anything so we can call it a match too
    (i - 1, j - 1)

    CASE 2 : '*' in p
    * can match with any no. of characters in s
    s = a a b (a)
    p = a (*)

    CASE 3 : s = a, p = b
    if char dont match we wont go further and return false

    so we can have many possibilities
    * can match with 0 char from s, can match with 1, 2 .....
    so we make all calls and || OR the result

    for all calls make 2 calls (i - 1, j) | (i, j - 1) recursively we will be able to make all calls

    BASE CASES :
    if both i and j less than 0 means both strings matched and empty --> true
    if p string is over and s still has left, we cant match more     --> false
    if s over but p not over, since we can match * with empty space also
    so we check in p till index j if we have all stars than return true else false 
    */
    int f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {

        // BASE CASES
        if (i < 0 && j < 0)  return true;                   // both over
        if (j < 0 && i >= 0) return false;                  // p over not s
        if (i < 0 && j >= 0) return checkAllStars(p, j);    // s over not p

        if (dp[i][j] != -1) return dp[i][j];                // state saved

        // CASE 1
        if (s[i] == p[j] || p[j] == '?') 
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);

        // CASE 2
        else if (p[j] == '*') 
            return dp[i][j] = f(i, j - 1, s, p, dp) | f(i - 1, j, s, p, dp);

        // CASE 3
        else return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {

        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return f(n - 1, m - 1, s, p, dp);
    }
};
