// https://leetcode.com/problems/4sum/
// will be done same as 3sum
// PREREQ - TWO SUM II  && 3SUM

class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        // sort the vector
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        // take 2 elements in n*n time using two loops
        for (int i = 0; i < nums.size(); ){
            for (int j = i + 1; j < nums.size(); ){
                
                // for the 3rd and 4th element use two pointer technique in sorted array
                int left = j + 1;
                int right = nums.size() - 1;
                
                while (left < right){
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];
                    
                    if (sum > target) right--;
                    else if (sum < target) left++;
                    else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        
                        // check for repeated numbers
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                }
                j++;
                // check for repeated numbers
                while (j < nums.size() && nums[j] == nums[j - 1]) j++;
            }
            i++;
            // check for repeated numbers
            while (i < nums.size() && nums[i] == nums[i - 1]) i++;
        }
        return result;
    }
};
