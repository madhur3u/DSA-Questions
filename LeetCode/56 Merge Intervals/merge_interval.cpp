// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        // sort all intervals acc to 1st value of intervals
        sort(a.begin(), a.end());
        
        // ans hold the ans and push the 1st 
        vector<vector<int>> ans;
        ans.push_back(a[0]);
        
        // array start from 1 as 0th interval already pushed
        for (int i = 1; i < a.size(); i++){
            
            // to get the last interval index calculate n, else ans.back()[1] can also be used
            int n = ans.size() - 1;
            
            // we compare the last pushed interval with the ith interval
            // if the end of ans is >= start of a[i] then we have to merge the interval
            // so we update the end of ans[n]
            // max(a[i][1], ans[n][1]) is done to take care of cases when merging interval like ans --> [1,10] , a[] --> [3,5] 
            // where the next interval is totally inside so we take max of 10, 5 for the end of ans
            if (ans[n][1] >= a[i][0]) 
                ans[n][1] = max(a[i][1], ans[n][1]);
            
            // if interval not merging push it into the ans
            else ans.push_back(a[i]);
        }
        return ans;
        
    }
};
