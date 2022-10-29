// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/solutions/1676833/c-largest-growing-time-first-with-illustrations/

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int, int>> time;

        // make pair with grow time as 1st as we will sort acc to grow time
        // we will first plant the seed which has max grow time for minimum time 
        for (int i = 0; i < n; i++) 
            time.push_back({growTime[i], plantTime[i]});
        sort(rbegin(time), rend(time));     // sorting vector in reverse using reverse iterators

        // traverse in sorted pair array
        int ans = 0, curr = 0;
        for (auto [g, p] : time) {

            // curr holds the plant time of previous seed as we plant the next seed after the prev planting done
            // we take max of total prev time and curr + p + g, as the grow time of prev could be greater than total time taken by current seed to bloom
            ans = max(ans, curr + g + p);
            curr += p;
        }
        return ans;
    }
};

/*
Algorithm

    sort the seeds by their growing time in decreasing order.
        we don't care about the planting time while sorting.
    while iterating through the sorted seeds, keep track of the current largest full bloom time tot and 
    current ending time of plantings cur. Update them as follow:
        tot = max(tot, cur + seed[i].plantingTime + seed[i].growingTime
        cur += seed[i].plantingTime
    after going through all seeds, tot is the answer.

*/
