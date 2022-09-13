// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        
        // neg will tell us if ans will be neg or not, num will hold integer string with sign
        bool neg = false;
        string num = "";
        
        // this loop will make the integer's string with sign
        // depending upon the constrains given
        for (char ch : s) {
            
            if (ch >= '0' && ch <= '9') num += ch;
            else if (ch == ' ' && num.size() == 0) continue;
            else if ((ch == '+' || ch == '-') && num.size() == 0) num += ch;
            else break;
        }
        // if first value of string has -, set neg flag true
        if (num[0] == '-') neg = true;
        
        // if sign present in 0th index
        // we will start making our integer from 1st value
        int idx = 0;
        if (num[0] == '-' || num[0] == '+') idx = 1;
        
        // this will hold absolute value of our integer
        // long long to not get overflow 
        long long int ans = 0;
        
        // making our integer from num
        for (int i = idx; i<num.size(); i++) {
            
            // adding the value from starting
            ans = ans*10 + (num[i] - '0');
            
            // this will prevent overflow
            // as this is int max limit we do not need to cross that
            // can also use 2147483647
            if (ans > INT_MAX) break;
        }
        // adding sign to ans acc to neg flag
        if (neg) ans = 0 - ans;
        
        // checking constrains of int and return ans or int max, min
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        else return ans;
    }
};
