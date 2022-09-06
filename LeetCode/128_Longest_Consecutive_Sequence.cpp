// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // push the array into a set
        // length will tell us the current consecutive subsequence length we found
        // ans will have the max of length
        unordered_set<int> st(nums.begin(), nums.end());
        int length = 0, ans = 0;
        
        // traverse in array
        for (int val : nums){
            
            // we need to find the starting point of the sequence
            // so for val to be starting point of seq, val - 1 will not exist in our set
            // so if val - 1 do not exist in set we consider that to be our stating point of seq
            if (st.find(val-1) == st.end()){
                
                // initialize length  = 0
                length = 0;
                
                // now we will run this loop till our sequence is present in our set
                // and inc the value of length , val  + length will be the next no. 
                // which we check in while loop
                while (st.find(val + length) != st.end()){
                    length++;
                }
            }
            // put max value of length in ans 
            ans = max(ans, length);
        }
        return ans;
    }
};
