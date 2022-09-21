// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        // calculate the sum of even no.s present in array initially
        int sum = 0;
        for (int i : nums) if (i % 2 == 0) sum += i;
        
        vector<int> ans;
        
        for (auto q : queries){
            
            // extracting the index and value
            int index = q[1], val = q[0];
            
            // first subtract the current value of array from sum
            // if it was even and do noting if it was odd
            if(nums[index] % 2 == 0) sum = sum - nums[index];
            
            // now update the array
            nums[index] += val;
            
            // if the value now even in nums add it to the sum
            // since we deleted the old value when it would have been even so 
            // we dont have to worry about case when both are even
            if (nums[index] % 2 == 0) sum = sum + nums[index]; 
            
            ans.push_back(sum);
        }
        return ans;
    }
};

/*
previous for loop for queries where we checking all conditions and updating nums later

        for (auto q : queries){
            
            if (q[0] % 2 == 0 && nums[q[1]] % 2 == 0) {
                sum = sum + q[0];
            }
            else if (q[0] % 2 != 0 && nums[q[1]] % 2 != 0){
                sum = sum + (nums[q[1]] + q[0]);
            }
            else if (q[0] % 2 != 0 && nums[q[1]] % 2 == 0){
                sum = sum - nums[q[1]];
            }
            nums[q[1]] = nums[q[1]] + q[0];
            ans.push_back(sum);
        }
*/
