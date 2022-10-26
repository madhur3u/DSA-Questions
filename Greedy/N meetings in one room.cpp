/*
Say if you have two meetings, one which gets over early and another which gets over late. 
Which one should we choose?  If our meeting lasts longer the room stays occupied and we lose our time. 
On the other hand, if we choose a meeting that finishes early we can accommodate more meetings. 
Hence we should choose meetings that end early and utilize the remaining time for more meetings.

make a pair vector with {end, start}
sort pair so the meeting which end early are in left

limit -> ending time of last meeting which we put in our ans, for next meeting to be valid its start > limit
ans = 1, initially as 1st pair will always be valid, least end value
*/
class Solution {
    public:
    int maxMeetings(int start[], int end[], int n) {
        
        // male {end, start} pair and sort
        vector<pair<int,int>> meeting(n);
        for (int i = 0; i < n; i++) {
            meeting[i].first = end[i];
            meeting[i].second = start[i];
        }
        sort(meeting.begin(), meeting.end());
        
        // initial limit willbe 1st meeting end time and ans = 1
        int limit = meeting[0].first;
        int ans = 1;
        
        // iterate from 2nd meeting till end
        for (int i = 1; i < n; i++) {
            
            // check if meeting valid, update limit to current meeting end if valid, ans++
            if (meeting[i].second > limit) {
                ans++;
                limit = meeting[i].first;
            }
        }
        return ans;
    }
};
