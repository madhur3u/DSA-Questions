/*
a -> no. of subarray with at most k odd numbers
b -> no. of subarray with at most (k - 1) odd numbers 

no. of subarrays with K odd numbers = a - b;
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
  
    // find no. of subarray with at most k odd numbers
    int atMostK(vector<int>& nums, int k) {

        if (k < 0) return 0;

        int res = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {

            // taking oddcount in k
            if (nums[r] & 1) k--;

            // if k<0 means more than k odd no.s accomodated so dec window length from start
            while (k < 0){
                if (nums[l] & 1) k++;
                l++;
            }
            // total no. of subarrays b/w l and r with at most k element, add to res
            res += (r - l + 1);
        }
        return res;
    }
};
