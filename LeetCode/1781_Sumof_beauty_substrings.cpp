// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
// bruteforce is the best solution
// in n^2 time we can calculate the substring and check for ans

class Solution {
public:
    
    // this compute the diff b/w min and max el in the count array and return that
    // also min should not be 0, as it has to be the minimum freq so && a[i] > 0
    int computeBeauty (int a[]){
      
        int max = 0;
        int min = INT_MAX;
        for (int i = 0; i < 26; i++){
            if (a[i] > max) max = a[i];
            if (a[i] < min && a[i] > 0) min = a[i];
        }
        return max - min;
    }
    
    int beautySum(string s) {
        
        // sum will have total beauty of all substring
        int sum = 0;
        
        // i is the the starting point of substring
        for (int i = 0; i < s.size() - 1; i++){
            
            // this array will store frequency of all elements b/w i and j
            // currently it will have all zeroes
            // since all are lowercase so static array of 26 length
            int freq[26] = { 0 };
            
            // j loop start from i till end to get all elements
            for (int j = i; j < s.size(); j++){
                
                // inc the frequency of element by 1
                // and compute sum by adding beauty of current substring to it
                freq[s[j] - 'a']++;
                sum = sum + computeBeauty(freq);
            }
        }
        return sum;
    }
};
