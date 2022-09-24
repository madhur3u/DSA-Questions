// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // temp vector sb to store subset
        vector<int> sb;
        generate_subsets(0, nums, sb);
        return res;
    }
    
    void generate_subsets(int index, vector<int> nums, vector<int> &sb){
        
        // case when all elements of array are parsed index will be equal to nums.size()
        // we push sb to res and return
        if (index == nums.size()){
            res.push_back(sb);
            return;
        }
        // not taking the element, sb is sent as it is, index increased
        generate_subsets(index + 1, nums, sb);
        
        // taking the current index element
        // push the current element into sb, call fn again index increased
        // remove the element from sb before we return
        sb.emplace_back(nums[index]);
        generate_subsets(index + 1, nums, sb);
        sb.pop_back();
    }
};
/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

we can see that we have to take an element or do not take an element
so in recursion we go to a particular index in nums (0 to n)
in one call we do not take that element and in another call we take that element
*/
