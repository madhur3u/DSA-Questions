class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string, int> mp;  
        int ans = 0;
        int unpaired = 0;   // this will have count of all same both letter string which dont find a pair

        for (string word : words) {

            // if both letter of strings are same
            if (word[0] == word[1]) {

                // if we found a pair ex. gg appears once before and now appear again
                // so we found mirror image hence adding both to ans, +4
                // dec unpaired count as gg is not unpaired now, dec count from map also
                if (mp[word] > 0) {     
                    unpaired--;
                    ans += 4;
                    mp[word]--;
                }
                // else inc unpaired count and map count
                else {
                    unpaired++;
                    mp[word]++;
                }
            }
            // if both words are different
            else {
                string rword(word.rbegin(), word.rend());   // reverse of word

                // if mirror image found, ans +4, dec count of rword, word was never added to map so no need
                if (mp[rword] > 0) {
                    ans += 4;
                    mp[rword]--;
                }
                // else inc count of word
                else mp[word]++;
            }
        }
        // if we have even one unpaired we will add only of of them so +2
        // as in case of cc, ll, xx 3 unpaired
        // we can add only 1 in middle 
        if (unpaired > 0) ans += 2;
        return ans;
    }
};
/*
2 letter words can be of 2 types:

    Where both letters are same
    Where both letters are different

Based on the above information:

    If we are able to find the mirror of a word, ans += 4
    The variable unpaired is used to store the number of unpaired words with both letters same.
    Unpaired here means a word that has not found its mirror word.
    At the end if unpaired same letter words are > 0, we can use one of them as the center of the palindromic string.

*/
