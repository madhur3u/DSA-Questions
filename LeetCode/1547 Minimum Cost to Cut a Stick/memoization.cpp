class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        
        if (i > j) return 0;                    // base case when i > j, cut cant be made
        if (dp[i][j] != -1) return dp[i][j];    // state already computed
        int cut = INT_MAX;                      // set initial cut to be max
        
        // we try to make cut at every given point from i to j in cuts array
        // for each cut we compute the cost and minimise it 
        for (int k = i; k <= j; k++) {
            //             current price to be added        left subproblem      right subproblem
            cut = min(cut, cuts[j + 1] - cuts[i - 1] + f(i, k - 1, cuts, dp) + f(k + 1, j, cuts, dp));
        }
        
        return dp[i][j] = cut;
    }
    int minCost(int n, vector<int>& cuts) {

        int c = cuts.size();    // c is original size of cuts array    
        cuts.push_back(0);      // add 0 and size of stick = n in the cuts array
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());     // sort array so cuts are independent

        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));  // dp 
        return f(1, c, cuts, dp);                           // make partition dp call (1, c)
    }
};
