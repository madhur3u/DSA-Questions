class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // unorderd map to store all anagrams together in a vector
        // key will be the sorted form of anagram
        unordered_map <string, vector<string>> mp;

        // iterate in vector, sort the string and place original string in vector
        // this way we will have all anagarams together
        // for -> eat, ate, tea
        // aet : {eat, ate, tea}
        for (string& s : strs) 
            mp[sortLowercase(s)].emplace_back(s);
        
        // ans 2d vector of size map
        vector<vector<string>> ans;
        ans.reserve(mp.size());

        // iterate in map and place 2nd in ans
        for (auto& it : mp) 
            ans.emplace_back(it.second);
        
        return ans;
    }

    // sorting lowercase string in O(max(N, 26));
    string sortLowercase (string s) {

        // make freq array
        int freq[26] = {};
        for (char& ch : s) freq[ch - 'a']++;

        string ans = "";

        // iterate in freq array and place characters in sorted order in ans
        for (int i = 0; i < 26; i++) {
            while (freq[i]--) {
                ans.push_back('a' + i);
            }
        }
        return ans;
    }
};
