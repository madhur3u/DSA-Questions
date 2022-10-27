class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& A) {
        
        // sort based on start time
        sort(A.begin(), A.end());

        // maintain end initially as 1st iterval end time
        int end = A[0][1];
        int ans = 0;

        // iterate from 2nd intervaltill end
        for (int i = 1; i < A.size(); i++) {

            // we take smaller ends in our ans as using that we can maximise no. of intervals
            // or minimise removing intervals if we pop the bigger end time intervals
            if (A[i][0] < end) {

                // inc count of ans as we are removinf a interval here
                ans++;
                // update end to be min of both ends, taking smaller interval in consideration
                end = min(end, A[i][1]);
            }
            // if interval valid just update end to its end time
            else 
                end = A[i][1];
        }    
        return ans;
    }
};
