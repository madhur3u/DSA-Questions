// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    
    // this func will give us int value for roman number input
    int roman(char c) {
        switch(c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    
    int romanToInt(string s) {
        
        // store the int of last value in ans
        int ans = roman(s[s.size() - 1]);
        
        // iterate from 2nd last till 0th index
        for (int i = s.size() - 2; i >= 0; i--){
            
            int current_val = roman(s[i]);
            int prev_val = roman(s[i + 1]);
            
            // if the roman number to the right is bigger we decrease our answer
            // else inc ans by that roman numeral's int value
            if (current_val < prev_val) ans = ans - current_val;
            else ans = ans + current_val;
            
        }
        return ans;
    }
};
