// https://leetcode.com/problems/house-robber/solutions/156523/from-good-to-great-how-to-approach-most-of-dp-problems/

// RECURSIVE - MEMOIZATION SOLUTION - TOP DOWN
// O(N) time, O(N) space because of recursion stack (TOP - DOWN)
// we use memo array to store previous results so we don't compute again
class Solution {
public:
    vector<int> memo;               // memo array
    int rob(vector<int>& nums) {

        int n = nums.size();        // n
        memo.resize(n + 1, - 1);    // set memo array size and place all -1

        return dfs(nums, n - 1);    // recursion call
    }
    int dfs(vector<int>& nums, int i) {

        if (i < 0) return 0;                // BASE CASE
        if (memo[i] >= 0) return memo[i];   // if ith result was already calculated retrn that

        // we come here if ith result was not calculated 
        // calculate it using normal rec technique of taking and not taking the ith element
        // if we take ith el then next el we take will be i - 2 th el -> dfs(nums, i - 2) + nums[i]
        // if we dont take ith element so we can take i - 1 th element -> dfs(nums, i - 1)
        // also we need to maximise ans so take max of both take and not take cases
        int result = max(dfs(nums, i - 2) + nums[i], dfs(nums, i - 1));

        // store current state result in memo array
        memo[i] = result;
        return result;
    }
};

// RECURSIVE SOLUTION
/*
we have two choices -> rob current house OR dont' rob curr house
if robbing ith house, means next house we can rob is (i - 2)th house
if not robbing curr house next house we can rob is (i - 1)th house
take max of both cases

class Solution {
public:
    int rob(vector<int>& nums) {
        return dfs(nums, nums.size() - 1);
    }
    int dfs(vector<int>& nums, int i) {

        if (i < 0) return 0;
        return max(dfs(nums, i - 2) + nums[i], dfs(nums, i - 1));
    }
};
This algorithm will process the same i multiple times and it needs improvement. TLE.
*/
