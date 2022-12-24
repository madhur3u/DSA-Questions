// https://leetcode.com/problems/domino-and-tromino-tiling/solutions/1620975/c-python-simple-solution-w-images-explanation-optimization-from-brute-force-to-dp/

class Solution {
public:
    int mod = 1e9 + 7;
    int f(int n, bool gap, vector<vector<int>>& dp) {

        if (n < 0) return 0;        // base case
        if (n == 0) return !gap;    // if gap remains and we reach end return 0, else return 1
        if (dp[n][gap] != -1)       // if state saved in dp
            return dp[n][gap];

        // if previously gap exist
        // we can put either one of the tromino tile and no gap will be left
        // or we can put a domino tile 1 x 2 which will leave us with one gap
        if (gap) 
            //                   place tromino no gap    place domino gap      mod the ans
            return dp[n][gap] = (f(n - 1, false, dp) + f(n - 1, true, dp)) % mod;
        
        // when no gap present we have 4 choices
        // 1 place domino standing will take up 1 column and no gap -> f(n - 1, false, dp)
        // 2 place 2 domino sideways take up 2 cols and no gap      -> f(n - 2, false, dp)
        // 3 place either of tromino with gap side in 2nd col, we will cover 2 cols with gap remain
        // so for 3 we can have 2 ways hence   --> 2l*f(n - 2, true, dp) , l for long overflow
        return dp[n][gap] = (f(n - 1, false, dp) + f(n - 2, false, dp) + 2l*f(n - 2, true, dp)) % mod;
    }
    int numTilings(int n) {

        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return f(n, false, dp);
    }
};
/*
l, ul, ll, etc denotes numbers with type long, unsigned long, long long, etc. In the above case, 2l denotes long int 2.

It basically implicity typecasts to long & I have used it to avoid overflow. This allows us to use dp of int instead of long since after ever mod operation, the results are int but it could overflow before mod which is why 2l...
*/
