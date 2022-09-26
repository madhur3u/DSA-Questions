// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    
    // make global array keypad and res to store ans
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string>res;
    
    vector<string> letterCombinations(string digits) {
        
        // when string is empty
        if (digits.size() == 0) return res;
        
        // fn call with digits, initial index 0 and empty string which forms our answer in fn call
        keypadC(digits, 0, "");
        return res;
    }
    
    void keypadC(string digits, int i, string ans){
        
        // BASE CASE : when all digits are parsed in string
        // push ans in res and return
        if (i == digits.size()){
            res.emplace_back(ans);
            return;
        }
        // index at which we look in keypad to form combination
        int idx = digits[i] - '0';
        
        // for each letter in that digit
        // call function, we do that using for loop
        // in fn call, inc index and add ch to ans
        for (char ch : keypad[idx])
            keypadC(digits, i + 1, ans + ch);
    }
};
/*
Time: O(4^N * N), where N <= 4 is length of digits string. Here, 4 is chosen assuming the worst case where each digit will be 7 or 9.
Extra Space (without counting output as space): O(N), it's the depth of stack memory.
*/
