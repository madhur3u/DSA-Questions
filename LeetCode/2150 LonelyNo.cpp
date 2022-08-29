// https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
// You are given an integer array nums. A number x is lonely when it appears only once, and no adjacent numbers (i.e. x + 1 and x - 1) appear in the array.

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        // ans will be stored in this vector
        vector<int> ans;
      
        // one method could be sorting array and check for subsequent elements but that is nlogn
        // since we deal with freq also therefor we can use hashmap
        // create map and put array element as key and freq as values
        unordered_map<int, int> mp;
        for(int i : nums) mp[i]++;
        
        // iterating in map
        for (auto val:mp){
            
            // this is the condition which we has for a number to be lonely
            // mp.count(val.first + 1) == 0 && mp.count(val.first - 1) == 0 check for adjacent no. in map in O(1)
            // checking freq also
            if(val.second == 1 && mp.count(val.first + 1) == 0 && mp.count(val.first - 1) == 0)
                ans.push_back(val.first);
        }
        return ans;
    }
};
