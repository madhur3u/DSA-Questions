// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        permutations(0, nums);
        return res;
    }
    void permutations(int idx, vector<int>& nums){
        
        // BASE CASE, push the permutation in res and return
        if (idx == size(nums)) {
            res.emplace_back(nums);
            return;
        }
        // here we are taking each digit from idx to n
        // in the idx position we are putting each digit once and sending for next fn
        // inc index for that
        // so in case of [1, 2, 3] idx = 0
        // for the 1st for loop we will have 3 fn calls for  
        // [1,2,3](1 and 1 swap) , [2,1,3] (1 and 2 swap), [3,2,1](1 and 3 swap) and in next one idx = 0+1
        // so like this we will hae each digit at all given positions, 1st we done for 0th pos then for 1st and so on
        // reswap to get original array
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            permutations(idx + 1, nums);
            swap(nums[idx], nums[i]);
        }
    }
};
