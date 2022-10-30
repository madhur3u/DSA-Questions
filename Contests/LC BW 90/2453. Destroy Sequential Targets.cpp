// find modulo, rem of each el with space 

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        
        // we store freq of remainder with the minimum number which gave us that remainder in pair
        // key will be the reminder
        unordered_map<int, pair<int, int>> mp;
        int maxf = 0;   // max freq of remainder is stored in maxf

        // iterate in muns
        for (int& num : nums) {
            int mod = num % space;  // find remainder

            // if we got this rem for first time, min num will be num only
            // else update 2nd el of pair with min of currently stored and num
            if (mp.find(mod) == mp.end())   
                mp[mod].second = num;
            else                            
                mp[mod].second = min(mp[mod].second, num);
            
            // inc freq of current remainder and calculate maxf
            mp[mod].first++;
            maxf = max(maxf, mp[mod].first);
        }

        int ans = INT_MAX;

        // iterate in map at all those remainder whose freq in maxf and take the min element from them
        for (auto it : mp) {
            if (it.second.first == maxf) 
                ans = min(ans, it.second.second);
        }
        return ans;
    }
};
