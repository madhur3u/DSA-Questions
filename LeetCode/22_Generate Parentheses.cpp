// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        // ans store the result, str the string we pass in fn
        vector<string> ans;
        string str;
        
        generate_Parentheses(str, n, n, ans);
        return ans;
    }
    
    void generate_Parentheses(string &str, int open, int close, vector<string> &ans){
        
        // invalid case, when no. of closed brackets are more than open brackets
        // or when no. of open brackets > n, so open become -ve < 0
        if (open > close || open < 0) return; 
        
        // base case when both open and close become zero
        // push the string into ans
        if (open == 0 && close == 0) {
            // cout << str << endl;
            ans.push_back(str);
            return;
        }
        
        // push a open bracket, call fn again
        // pop the open bracket in backtracking to form new pair in next recursive call
        // open - 1, to inc count of open brackets which initially should be n
        str.push_back('(');
        generate_Parentheses(str, open - 1, close, ans);  
        str.pop_back();
        
        // push close bracket, call fn, pop while backtracking, decrease close in fn
        str.push_back(')');
        generate_Parentheses(str, open, close - 1, ans); 
        str.pop_back();
    }
};
