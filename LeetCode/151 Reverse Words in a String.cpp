// O(N) time and space
// https://leetcode.com/problems/reverse-words-in-a-string/solutions/1531693/c-2-solutions-o-1-space-picture-explain-clean-concise/ 
// abobe link O(1) space

class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        stack<string> st;   // make stack
        int i = 0, j;       // two pointers
        
        while (i < n) {     // traverse string
            
            // ignore white spaces
            if (s[i] == ' ') i++;

            // extract word and put it in stack
            else {
                // take 2nd pointer j and move it forward till we find white space or string ends
                // when while loop end i will point to start of word and j the end of word + 1 
                j = i;  
                while (j < n && s[j] != ' ') {
                    j++;
                } 
                // push the substring means word b/w i and j in stack and inc i to j + 1 for next word
                st.push(s.substr(i,(j - i)));
                i = j + 1;
            }
        }
        // make ans from stack
        string ans;
        while (!st.empty()) {
            if (st.size() == 1) ans += st.top();
            else                ans += st.top() + " ";
            st.pop();
        }
        return ans;
    }
};
