// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
/*
If we and a number with its smaller numbers bitwise. The result will always be less than the max of both of them. 
For ex. 2 -> 1 0 and 6 -> 1 1 0, if we and both of them 2&4 the result will be 1 0 = 2 which is less than 6. This will be true for all values.

So in this question we need to first find the maximum element, and then its freq in subarray, 
means we need to find max consecutive occurrence of the maximum number.
*/

class Solution {
public:
    int longestSubarray(vector<int>& a) {
        
        //STEP 1
        int maxnum = 0;
        
        for (int num : a){
            if (num > maxnum) maxnum = num;
        }
        
        // STEP 2
        int freq = 0, maxfreq = 0;
        
        for (int num : a){
            
            // inc freq if element equals maxnum else reset it back to zero
            if (num == maxnum) freq++;
            else freq = 0;
            
            // update maxfreq
            maxfreq = max(freq, maxfreq);
        }
        return maxfreq;
    }
};
