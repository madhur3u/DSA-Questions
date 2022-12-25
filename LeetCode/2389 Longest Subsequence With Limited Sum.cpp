class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        /*
        Sort input A, since we care the sum and doesn't care the order.
        Calculate the prefix sum of A, since we want to know the accumulate sum.
        Binary seach each query q in query, and the index is the result.
        return result res. 
        */

        int n = nums.size();
        vector<int> ans;

        sort(nums.begin(), nums.end());                        
        for (int i = 1; i < n; i++) nums[i] += nums[i - 1];

        for (int& q : queries) {

            // upper bound give us address of q or the num before q in nums
            // we subtract the 1st address nums.begin() from the upper bound to get index
            ans.push_back(upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        }

        return ans;
    }
};
