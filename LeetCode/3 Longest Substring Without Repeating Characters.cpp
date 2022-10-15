// O(n) time, O(128) space
// https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/2132830/visual-explanation-sliding-window-java/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int longest_substr = 0;

        int nextIndex[128] = {0};

        for (int l = 0, r = 0; r < n; r++) {

            // updating left index 
            // if element of left was seen before then the index next to that element will be saved in array
            l = max(l, nextIndex[s[r]]);

            // update longest substr using r and l
            longest_substr = max(longest_substr, r - l + 1);

            // update nextIndex to r + 1 means next index in string  
            nextIndex[s[r]] = r + 1;
        }
        return longest_substr;
    }
};
/*
Key Observation:
Once we've landed on a character we've seen before, we want to move the left pointer of our window 
to the index after the last occurrence of that character.
*/
