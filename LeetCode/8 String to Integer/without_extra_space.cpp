// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        
        // sign will tell us if ans will be neg or not, num will hold integer string with sign
        int sign = 1;
        int idx = 0;
        
        // clearing the white spaces, idx will point to 1st non white space character
        while (idx < s.size() && s[idx] == ' ') idx++;
        
        // checking if any sign present and assigning value to sign
        if (idx < s.size() && (s[idx] == '-' || s[idx] == '+' )){
            if (s[idx] == '-') sign = -1;
            idx++;
        } 
        
        // now idx will point to the starting of number string(if present)
        // make end_idx which will tell us ending of number string
        int end_idx = idx;
        
        // checking till the character is a number, inc end_idx
        // last value of end index will point either out of string or non numerical character
        while (end_idx < s.size() && s[end_idx] >= '0' && s[end_idx] <= '9') end_idx++;
        
        // long to prevent overflow
        long long int ans = 0;
        
        // making our integer from num
        for (int i = idx; i<end_idx; i++) {
            
            // adding the value from starting idx till end
            ans = ans*10 + (s[i] - '0');
            
            // this will prevent overflow
            // as this is int max limit we do not need to cross that
            // can also use 2147483647
            if (ans > INT_MAX) break;
        }
        // adding sign to ans
        ans = ans * sign;
        
        // checking constrains of int and return ans or int max, min
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        else return ans;
    }
};
