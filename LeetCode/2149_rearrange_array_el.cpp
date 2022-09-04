// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// this code only for if no. of +ve and -ve el in array are equal

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        // initialize ans vector of n size with all 0
        vector<int> ans(nums.size(), 0);
        
        // positive and negetive indexes
        // 0 and 1 as we need to place them alternatively
	    int pi = 0, ni = 1;
	    
        // traverse in array
	    for (int num : nums){
            
            // if pos no found push it into ans at pi position
            // and inc pi by 2 as we need to push next pos num after one neg no.
            // thats why inc by 2
            if (num > 0){
                ans[pi] = num;
                pi+=2;
            }
            // for -ve num do same but with ni index
            else{
                ans[ni] = num;
                ni+=2;
            }
        }
        return ans;
    }
};
