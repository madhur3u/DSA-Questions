// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        
        // make a map of all values 
        unordered_map<char, int> mp = { { 'I' , 1 },
                                        { 'V' , 5 },
                                        { 'X' , 10 },
                                        { 'L' , 50 },
                                        { 'C' , 100 },
                                        { 'D' , 500 },
                                        { 'M' , 1000 } };
        
        // store the int of last value in ans
        int ans = mp[s[s.size() - 1]];
        
        // iterate from 2nd last till 0th index in 
        for (int i = s.size() - 2; i >= 0; i--){
            
            // if the roman number to the right is bigger we decrease our answer
            // else inc ans by that roman numeral's int value
            if (mp[s[i]] < mp[s[i + 1]]) ans = ans - mp[s[i]];
            else ans = ans + mp[s[i]];
            
        }
        return ans;
    }
};
