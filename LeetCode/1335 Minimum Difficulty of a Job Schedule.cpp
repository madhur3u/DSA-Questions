/*
question can be worder has
part the array into d subarrays such that sum of maximum of each subarray is minimum

so for that we need to make d - 1 cuts in array

since we need to see all subarray cobination we use dfs for that
memorize previous result in dp to reduce time
*/

class Solution {
public:
    int n;
    int minDifficulty(vector<int>& job, int d) {

        // case when no. of subarrays to be formed > array lenght so return -1
        // if no. of subarray == array size, means each element is subarray so return sum of array 
        if (d > job.size()) return -1;
        if (d == job.size()) return accumulate(job.begin(), job.end(), 0);

        n = job.size();

        // 2d vector to store previous result of size [d+1][n]
        vector<vector<int>> dp(d + 1, vector<int>(n, -1));
        // call dfs array with both arrays and 0 as 1st cut position, d is no. of subarrays
        return dfs(job, d, 0, dp);        
    }
    int dfs(vector<int> &job, int days, int cut, vector<vector<int>> &dp) {

        // when no. of subarrays left > elements left in array
        if (days > n - cut) return -1;

        // check if result stored previously if it is return the value
        if (dp[days][cut] != -1) return dp[days][cut];
        
        // forming reslut when  not precomputed, make its max
        // current difficulty will have max in our subarray
        int res = INT_MAX;
        int curr_diff = 0;

        // i will traverse from current cut position till (n - d)
        for (int i = cut; i <= n - days; i++) {

            // computing max in subarray
            curr_diff = max(curr_diff, job[i]);

            // if we can part our array means days > 1
            // make cut here at current i, so at  i + 1 we have another subarray, and compute for next subarray
            // take the minimum of result and the return val + current difficulty (subarray) max
            if (days > 1) 
                res = min(res, dfs(job, days - 1, i + 1, dp) + curr_diff);

            // for days == 1, we just compute max in current subarray from cut till end in array job
            else
                res = curr_diff;
        }
        // store res in dp and return
        return dp[days][cut] = res;
    } 
};
