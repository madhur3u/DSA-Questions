class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        int count[26][26] = { 0 };  // a 2d vector of 26*26 means all combinations of 2 letter words can be stored here we store count of them
        int ans = 0;

        // iterate in words
        for (string word : words) {

            // extract int of both letters
            int a = word[0] - 'a', b = word[1] - 'a';

            // if count of reverse already > 0 means we found a pair or mirror image +4
            // dec count of rword
            if (count[b][a]) {
                ans += 4;
                count[b][a]--;
            }
            // else inc count of word
            else count[a][b]++;
        }
        // checking for strings with same elements if any unpaired string left
        // for same index will be same so we check each [i][i] index if any one > 0, +2
        for (int i = 0; i < 26; i++){
            if (count[i][i]) {
                ans+= 2;
                break;
            }
        }
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
