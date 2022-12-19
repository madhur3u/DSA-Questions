class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, 1);   // we make curr ans acc to prev stored lis in dp
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;  // this will help us printing lis

        int ans = 1;
        int li = 0;     // last index of lis willbe stored here

        for (int i = 1; i < n; i++) {               // curr index i
            for (int pi = 0; pi < i; pi++) {        // previous index pi
                if (nums[pi] < nums[i] && (1 + dp[pi]) > dp[i]) {
                    dp[i] = 1 + dp[pi];
                    parent[i] = pi;         // update parent of curr i as pi
                }
            }
            if (dp[i] > ans) {
                ans = dp[i];
                li = i;         // last index of the lis we get
            }
        }
        // PRINTING LIS   
        while (li != parent[li]) {
            cout << nums[li] << " ";
            li = parent[li];
        } 
        cout<<nums[li];
        return ans;
    }
};
