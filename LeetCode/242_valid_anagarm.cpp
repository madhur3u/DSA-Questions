// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) return false;
        
        // Since the problem statement says that "the string contains only lowercase alphabets", 
        // we can simply use an array to simulate the unordered_map and speed up the code.
        int count[26] ={};
        
        // traverse in both array, increase count if found in s
        // decrease count if found in t
        for (int i = 0; i <s.size(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        // if both are anagarams our count array finally will have all 0's
        // if any value is not 0 return false
        for (int i : count)
            if (i) return false;
        
        return true;
        
        
        /*
        This idea uses a hash table to record the times of appearances of each letter in the two strings
        s and t. For each letter in s, it increases the counter by 1 while for each letter in t, it decreases
        the counter by 1. Finally, all the counters will be 0 if they two are anagrams of each other.
        
        unordered_map<char, int> mp;
        for (auto ch : s) mp[ch]++;
        
        for (auto ch : t){
            if (mp.find(ch) == mp.end() || mp[ch] == 0) return false;
            mp[ch]--;
        }
        return true;
        */
    }
};
