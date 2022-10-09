// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/solutions/2678848/stack-it-up-easy-to-understand-c/
// DRY RUN PLEASE
class Solution {
public:

    // this fn tell us what is the min character present in the string s currently
    // it will check the freq of all el and send first character whose freq > 0
    // if all freq 0 we send max el so that inner while loop add all stack el to ans before ending
    char minChar(vector<int> freq) {

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return ('a' + i);
        }
        // z in last will let the inner while loop run when freq has all 0 as z is biggest
        // it will just add stack el in ans top to bottom
        return 'z';
    }

    string robotWithString(string s) {
        
        stack<char> t;
        string ans = "";

        // making freq array of 26 length which has freq of all ch in string s
        // initially set all to 0 and inc one by one when found
        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;

        // iterate in string s 
        for (char ch : s) {

            // push the current char to stack and dec its freq in freq array
            t.push(ch);
            freq[ch - 'a']--;

            // run loop when stack has element
            // ans the char in stack top has lesser or equal freq to the min char currently in s
            // this min we have el with min order in top 
            // since we making lex smallest string we push this el at top into our ans and pop
            // loop runs till condition satisfy 
            while (!t.empty() && t.top() <= minChar(freq)) {

                ans.push_back(t.top());
                t.pop();
            }
        }
        return ans;
    }
};
