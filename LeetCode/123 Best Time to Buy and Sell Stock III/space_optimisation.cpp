/*
Time Complexity: O(N*2*3)
Reason: There are three nested loops that account for O(N*2*3) complexity

Space Complexity: O(1)
Reason: We are using two external arrays of size ‘2*3’.
*/
class Solution {
public:
    int maxProfit(vector<int>& a) {
        
        int n = a.size();
        vector<vector<int>> curr(2,vector<int>(3, 0)), next(2,vector<int>(3, 0));  
        /*
        3d dp -> constant space 2d dp as we only need current and next row, i and i + 1 rows
        if (i == a.size() || k == 0) return 0; 
        we will give 0 to array in base case so rather than forming base case initialise while dp to 0
        */    
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 1; buy >= 0; buy--) {
                for (int k = 2; k >= 1; k--) {

                    int profit = 0;
                    if (buy) {
                        int take = -a[i] + next[0][k];
                        int notTake =  0 + next[1][k]; 

                        profit = max(take, notTake);
                    }
                    else {
                        int take = a[i] + next[1][k - 1];
                        int notTake = 0 + next[0][k]; 

                        profit = max(take, notTake);
                    }
                    curr[buy][k] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
};
