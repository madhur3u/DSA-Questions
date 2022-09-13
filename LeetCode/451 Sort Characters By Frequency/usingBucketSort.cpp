// https://leetcode.com/problems/sort-characters-by-frequency/
/*
    Time: O(N), where N <= 5 * 10^5 is the length of string s.
    Space: O(N)
*/

class Solution {
public:
    string frequencySort(string s) {
        
        int n = s.size();
        
        // we first make a unorderd map which will map all chars with its freq
        // we cannot use this diretly as it is not in order
        unordered_map<char, int> char_freq;
        for (char ch : s) char_freq[ch]++;
        
        // so we make a bucket, 2D char vector of size n+1
        // as the max freq which we can have is n
        // the index will denote the freq and the inner vector will store all characters of that freq
        vector<vector<char>> bucket(n + 1);
        
        // iterate in map
        // and for a particularfreq push in the inner vector at freq position in bucket
        // for tree --> t-1, r-1, e-2 --> bucket -- > {{}, {r,t}, {e}, {}, {}}
        for (auto [ch, freq] : char_freq)
            bucket[freq].push_back(ch);
        
        // ths will hold ans
        string ans;
        
        // iterate in reverse order in bucket
        for (int freq = bucket.size() - 1; freq >= 1; freq--){
            
            // iterate in inner vector in bucket for > 1 characters
            // add the character, freq times into the ans string --> eert
            for (char ch : bucket[freq])
                ans.append(freq, ch);
                // ans = ans + string(freq, ch);
        }
        return ans;
    }
};
