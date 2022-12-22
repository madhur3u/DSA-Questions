// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// https://takeuforward.org/dynamic-programming/matrix-chain-multiplication-dp-48/
class Solution {
public:
    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        // if (i == j) return 0; base case 0 so no need
        
        for (int i = N - 1; i >= 1; i--) {
            for (int j = i + 1; j <= N - 1; j++) {
                
                int steps = 1e9;
                for (int k = i; k <= j - 1; k++) {
                    steps = min(steps, arr[i - 1]*arr[k]*arr[j] + dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = steps; 
            }
        }
        return dp[1][N - 1];
    }
};
/*
Time Complexity: O(N*N*N)
Reason: There are N*N states and we explicitly run a loop inside the function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.

Space Complexity: O(N*N)
Reason: We are using a 2D array ( O(N*N)) space.
*/
