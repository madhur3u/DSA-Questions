class Solution {
public:
    int maxProfit(int K, vector<int>& a) {
        
        int n = a.size();
        vector<vector<int>> curr(2,vector<int>(K+1, 0)), next(2,vector<int>(K+1, 0));  
        /*
        3d dp ->  2d dp as we only need current and next row, i and i + 1 rows
        if (i == a.size() || k == 0) return 0; 
        we will give 0 to array in base case so rather than forming base case initialise while dp to 0
        */    
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 1; buy >= 0; buy--) {
                for (int k = K; k >= 1; k--) {

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
        return next[1][K];
    }
};
