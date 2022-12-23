class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        int c = cuts.size();    // c is original size of cuts array    
        cuts.push_back(0);      // add 0 and size of stick = n in the cuts array
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());     // sort array so cuts are independent

        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));  // dp 

        for (int i = c; i >= 1; i--) {
            for (int j = i; j <= c; j++) {

                int cut = INT_MAX;
                for (int k = i; k <= j; k++) {
                    cut = min(cut, cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = cut;   
            }
        }
        return dp[1][c];
    }
    /*
Time Complexity: O(N*N*N)
Reason: There are 2 variables i and j, therefore, N*N states and we explicitly run a loop inside the function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.

Space Complexity: O(N*N) 
Reason: We are using a 2D array ( O(N*N)).
    */
};
