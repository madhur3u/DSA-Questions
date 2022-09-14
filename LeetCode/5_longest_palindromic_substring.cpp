// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        
        // ans will hold the longest palindrome substr
        // temp will hold palindromes in each iteration
        string ans = "", temp;
        
        // logic is to take everey element in string
        // for every string consider i as middle point and expand to left and right in every step
        // check if while expanding we are getting same elements if not end loop
        // and check the substring found if is longest
        for (int i = 0; i < s.size(); i++){
            
            // for odd
            // taking both left and right pointer at same place and expanding in function
            // func will return the palindrome found from i as middle
            // compare that with ans and if temp > ans, update ans
            temp = checkPalindromeFromMid (s, i, i);
            if (temp.size() > ans.size())
                ans = temp;
            
            // for even
            // taking left as i and right pointer as i + 1
            // using this we can check even length palindromes
            temp = checkPalindromeFromMid (s, i, i + 1);
            if (temp.size() > ans.size())
                ans = temp;
        }
        
        return ans;
        
    }
    // func to check palindrome from middle
    string checkPalindromeFromMid(string s, int left, int right){
        
        // while in index and till equal elements
        while (left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        // return the palindrome found 
        return s.substr(left + 1, right - left - 1);
    }
};
