class Solution {
public:
    // from house robber 1 
    int solve(vector<int>& nums, int l, int r) {

        int prev = nums[l];         // take base case in a variable
        int prev2 = 0;              // since while memo or tabulation we were only saving prev 2 states
        // so only 2 variables needed to store prev 2 states

        // traverse from l + 1, as lth index el already taken in prev, so start after that
        for (int i = l + 1; i <= r; i++) {

            int pick = nums[i] + prev2;     // pick curr element, no need of cond as initial prev2 = 0
            int non_pick = prev;            // not picking curr el

            int currMaxSum = max(pick, non_pick);   // max of both

            prev2 = prev;                   // save states
            prev = currMaxSum;
        }
        return prev;
    }
  
    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n == 1) return nums[0];

        int ans1 = solve(nums, 0, n - 2);   // taking 1st el not taking last el
        int ans2 = solve(nums, 1, n - 1);   // taking last el not taking 1st el

        return max(ans1, ans2);             // return max of both 
    }
};
