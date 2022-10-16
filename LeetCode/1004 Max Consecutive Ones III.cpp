class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int zeroCount = 0;
        int ans = 0;

        // l and r are the left and right pinters which will hold our current window
        for (int l = 0, r = 0; r < n; r++) {
            
            // if element in r is a 0, inc zero count
            if (nums[r] == 0) zeroCount++;

            // if zero count > k means we have accomodated more zeroes than needed
            // so we need to inc left pointer, dec window from start point
            // zero count will only be dec when we encounter a zero
            while (zeroCount > k){
                if (nums[l] == 0) 
                    zeroCount--;
                l++;
            } 
            // when we reach here we have a valid window with zero count <= k
            // so this window lenght is compared with ans and max will be taken
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
