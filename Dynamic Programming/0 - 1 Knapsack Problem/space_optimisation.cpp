// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
class Solution {
    public:
    int knapSack(int W, int wt[], int val[], int n) { 
        
        // since we use only 1 prev row so we can eliminate 2d dp and use a 1d dp
        // vector<vector<int>> dp(n, vector<int>(W+1, 0));
        vector<int> prev(W+1, 0);
        
        // forming 1st row using base case
        // if (i == 0) { if (wt[0] <= w) return val[0]; else 0, so initailly all as 0
        // now we make in 1st row every index from wt[0] to w equal to val[0]
        for (int i = wt[0]; i <= W; i++)
            prev[i] = val[0];
        
        // 2 loops as 2 indices to deal with i and w
        // i start from 1 as 0 taken in base case
        // paste the memo codewith changes
        for (int i = 1; i < n; i++) {
            
            // space opt in single row
            // as when we fill curr we need [w - wt[i]] index of prev row
            // this will surely be in left side
            // so if we start filling from index maxWeight to 0 we can fill same in just prev row only
            // as we dont req the right hand side el of the prev row
            for (int w = W; w >= 0; w--) {
                
                int notTake = 0 + prev[w];
                int take = -1;
                if (wt[i] <= w) take = val[i] + prev[w - wt[i]];
                
                prev[w] = max(take, notTake);
            }
        }
        return prev[W];
    }
};
/*
Time Complexity: O(N*W)
Reason: There are two nested loops.

Space Complexity: O(W)
Reason: We are using an external array of size ‘W+1’ to store only one row.
*/
