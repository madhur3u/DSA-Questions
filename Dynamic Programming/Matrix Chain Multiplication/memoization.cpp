// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// https://takeuforward.org/dynamic-programming/matrix-chain-multiplication-dp-48/
class Solution {
public:
    int f(int i, int j, int arr[], vector<vector<int>>& dp) {
        
        if (i == j) return 0;                   // base case
        if (dp[i][j] != -1) return dp[i][j];    // state already computed
        int steps = 1e9;                        // steps initial set as a big number
        
        // we need to partition array from i to j, try all partitions
        // for that we will run k from i t o j - 1 as we can have max (j - i) partitions
        // minimise each computations
        for (int k = i; k <= j - 1; k++) {
            //          prev   computed for current ijk      call for partition1      partition2
            steps = min(steps, arr[i - 1]*arr[k]*arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp));
        }
        
        return dp[i][j] = steps;    // save state in dp and return
    }
    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return f(1, N - 1, arr, dp);
    }
};
