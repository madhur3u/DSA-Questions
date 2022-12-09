// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// TABULATION SOLN
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int k){
        
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1)); // dp[i][target] target from 0 to k,  from 0 to n-1
        
        // base case 1 --> if (k == 0) return true; for all target index 0 mark true
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        // when arr[0] == target we mark true --> mark dp[0][arr[0]] as true
        // check if arr[0] less than equal to target else will go out of bounds
        if (arr[0] <= k) dp[0][arr[0]] = true;
        
        // since we had 2 variables index and target
        // make 2 loops for that
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= k; target++) {
                
                // not taking curr element
                bool notTake = dp[i - 1][target]; 
                
                // taking curr el, initially mark as false, check if arr[i] less than or equal to target
                // so it wont go out of bounds, if satisfy cond, take will be dp[i - 1][target - arr[i]]
                bool take = false;
                if (arr[i] <= target) take = dp[i - 1][target - arr[i]];
                
                dp[i][target] = take | notTake; // take OR of both store in dp
            }
        }
        return dp[n-1][k];  // since we start rec from n - 1, k --> it will have our ans
    }
};
