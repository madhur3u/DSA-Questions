/*
O(26*N)
consider a astring ABACA 
if we want to make this whole string with all A (since it apperas max times)
then we need to change 2 chars

so (window length) - maxElementFrequency is the minimum value of k which we need
we make a freq array from wchich we find most frequent element frequency and two pointers for window length
*/

class Solution {
public:
    int characterReplacement(string s, int k) {

        // freq vector with all 0
        vector<int> freq(26, 0);
        int res = 0;
        
        // two pointers left and right to create sliding window
        for (int l = 0, r = 0; r < s.size(); r++) {

            // update freq of right element
            freq[s[r] - 'A']++;

            // check if in current window we have (window length) - maxElementFrequency > k
            // if true means window have more values than we can flip so dec window from left
            // and keep on dec frequency
            while ((r - l + 1) - *max_element(freq.begin(), freq.end()) > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            // when we come here we will have a valid window so update res with max of res and current window size
            res = max(res, r - l + 1);
        }
        return res;
    }
};

//-------------------------------------------------------------------------------
// SOL 2 MORE EFFICIENT
// O(N)

class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);
        int res = 0;

        // rather than checking max every time we take a variable max freq which we update while we inc freq array 
        // logic is that if we get a max freq we dont need to check for lower freq than that as it will give us lesser window length and we already have bigger one in ans
        // and when a greater freq is there it will get updated
        int maxFreq = 1;
        
        for (int l = 0, r = 0; r < s.size(); r++) {

            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
