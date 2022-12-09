// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// SPACE OPT SOLN 
// Space Complexity: O(K)
// Time Complexity: O(N*K)
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int k){
        
        int n = arr.size();
        vector<bool> prev(k+1, 0), curr(k+1, 0);    // converting 2d dp to 1d dp
        
        /*
        base case 1 --> if (k == 0) return true; for all target index 0 mark true
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        for every row we should have 1st cell to be true always thats what we do in above 2d dp
        since prev will have each row and curr the curr row so we make thier 1st el true
        */
        prev[0] = curr[0] = true;
        
        /* when arr[0] == target we mark true --> mark dp[0][arr[0]] as true
        check if arr[0] less than equal to target else will go out of bounds
        if (arr[0] <= k) dp[0][arr[0]] = true;
        
        here we just need to replace dp[0] by prev as this is only for 1st row and 1st row stored in prev
        */
        if (arr[0] <= k) prev[arr[0]] = true;
        
        // since we had 2 variables index and target
        // make 2 loops for that
        // rather than dp[i - 1] we use --> prev as we store only 1 row
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= k; target++) {
                
                // not taking curr element
                bool notTake = prev[target]; 
                
                // taking curr el, initially mark as false, check if arr[i] less than or equal to target
                // so it wont go out of bounds, if satisfy cond, take will be dp[i - 1][target - arr[i]]
                bool take = false;
                if (arr[i] <= target) take = prev[target - arr[i]];
                
                curr[target] = take | notTake; // take OR of both store in dp
            }
            prev = curr;
        }
        return prev[k];  // since we start rec from n - 1, k --> it will have our ans
    }
};
