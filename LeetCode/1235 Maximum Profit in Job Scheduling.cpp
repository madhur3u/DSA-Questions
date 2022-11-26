class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();

        // push all job details together, endtime first as we sort acc to end time
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) jobs.push_back({endTime[i], startTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());     // sort jobs
        map<int, int> dp;                   // map will store profit till end time,{end time, profit till now}
        dp[0] = 0;                          // at 0 profit 0

        for (auto& job : jobs) {            // iterate in jobs

            // curr profit will be the profit our current job will give -> job[2]
            // ans the profit we are getting before starttime of curr job
            // for that we do binary search using upper bound for start time in map
            int curProfit = job[2] + prev(dp.upper_bound(job[1])) -> second;

            // if curr profit > max profit stored tinn now -> will be stored in last element of map
            // then we add this combination to map
            if (curProfit > dp.rbegin() -> second)
                dp[job[0]] = curProfit;
        }
        // after loop end we return max profit
        return dp.rbegin() -> second;
    }
};
/*
Time O(NlogN) for sorting
Time O(NlogN) for binary search for each job
Space O(N)

Sort the jobs by endTime.

dp[time] = profit means that within the first time duration,
we cam make at most profit money.
Intial dp[0] = 0, as we make profit = 0 at time = 0.

For each job = [s, e, p], where s,e,p are its start time, end time and profit,
Then the logic is similar to the knapsack problem.
If we don't do this job, nothing will be changed.
If we do this job, binary search in the dp to find the largest profit we can make before start time s.
So we also know the maximum cuurent profit that we can make doing this job.

Compare with last element in the dp,
we make more money,
it worth doing this job,
then we add the pair of [e, cur] to the back of dp.
Otherwise, we'd like not to do this job.
*/
