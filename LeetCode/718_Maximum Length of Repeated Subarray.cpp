// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        // make tabulation dp of n+1 * m+1 size
        // set all elements to zero using memset
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        
        int res = 0;
        
        // traverse in dp from (1,1)
        for (int i = 1; i < n + 1; i++){
            for (int j = 1; j < m + 1; j++){
                
                // compare nums1 and nums1
                // if equal place the sum of previous diagonal + 1
                // else 0
                // this way whenever we find the longest subarray the sum keep on inc
                // and max element of dp will be the ans
                if (nums1[i - 1] == nums2[j - 1])    dp[i][j] = dp[i - 1][j - 1] + 1;
                else                                 dp[i][j] = 0;
                
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

/*
a = 1 2 3 1
b = 2 3 4 5

dp[][]

0 0 0 0 0
0 0 1 0 0 -> 1 = prev diag(0) + 1
0 0 0 2 0 -> 2 = prev diag(1) + 1
0 0 0 0 3 -> 3 = prev diag(2) + 1 // max
0 1 0 0 0
*/
