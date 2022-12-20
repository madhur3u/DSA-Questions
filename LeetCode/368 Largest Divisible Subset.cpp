// same as tabulation 2 approach of LIS, just sort the array and change condition nums[i] % nums[pi] == 0

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1);   // we make curr ans acc to prev stored lis in dp
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;  // this will help us printing lis

        int li = 0;     // last index of lis willbe stored here
        int maxi = 1;

        for (int i = 1; i < n; i++) {               // curr index i
            for (int pi = 0; pi < i; pi++) {        // previous index pi
                if (nums[i] % nums[pi] == 0 && (1 + dp[pi]) > dp[i]) {
                    dp[i] = 1 + dp[pi];
                    parent[i] = pi;         // update parent of curr i as pi
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                li = i;         // last index of the lis we get
            }
        }
        // STORING Longest Divisible Subsequence using parent array  
        while (li != parent[li]) {
            ans.push_back(nums[li]);
            li = parent[li];
        } 
        ans.push_back(nums[li]);

        return ans;
    }
};
