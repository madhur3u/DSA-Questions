class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int, int> mp;     // map to store how many times a player lost a match
        for (auto& match : matches) {
            
            // player 0 is winning, so if it was first time player 1 played a match we make it 0
            // else we set it to what it was before, it might have lost few matched before
            mp[match[0]] = (mp.find(match[0]) == mp.end()) ? 0 : mp[match[0]];
            
            // if player lost match decrease by 1
            mp[match[1]]--;
        }
        // ans vector with 2 vectors
        vector<vector<int>> ans(2);

        // store whose freq is 0, means didnt lost match in ans0
        // those who lost one match itr.sec == -1, push in ans1
        for (auto& itr : mp) {
            if (itr.second == 0) ans[0].push_back(itr.first);
            else if (itr.second == -1) ans[1].push_back(itr.first);
        }
        // sort ans vector
        for (auto& itr : ans) {
            sort(itr.begin(), itr.end());
        }
        return ans;
    }
};
