// https://leetcode.com/problems/remove-outermost-parentheses/

/*
opened count the number of opened parenthesis.
Add every char to the result,
unless the first left parenthesis,
and the last right parenthesis.
*/

//                                     (()())(())
// value of opened for each bracket -->0121210121

class Solution {
public:
    string removeOuterParentheses(string s) {
        
        // opened count the no. of open brackets and will dec when found a close bracket
        // ans store return string
        int opened = 0;
        string ans = "";
        
        // checking every character in string
        for (auto ch : s){
            
            // if we encounter open bracket
            // when its first open bracket we do not add that as opened will be zero
            // and inc count of opened as one open bracket found, from now on if open bracket found push in ans
            if (ch == '('){
                if (opened > 0) ans += ch;
                opened++;
            }
            
            // we check if closed bracket is found
            // if its closed bracket of outermost open bracket
            // then value of opened will be one, so just opened--
            // else if its inner bracket the opened will be atleast 2
            // so we push it in ans, and dec opened--
            else {
                if (opened > 1) ans += ch;
                opened--;
            }
        }
        return ans;
    }
};
