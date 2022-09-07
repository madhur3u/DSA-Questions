// https://leetcode.com/problems/3sum/

// approach - sort the array , take the ith number and traverse from array ahead it
// in that array use the two sum II approach to find two numbers which along with ith num = 0
// push this into ans

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // sort the array to use two pointer approach
        // ans will hold the list of triplets
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        // first traversal to get the 1st number of triplet 
        // loop run till i < nums.size()-2 because we need triplet
        int i = 0;
        while (i < nums.size()-2) {
            
            // since array is sorted so if ith number is >0
            // we cannot make a triplet with sum 0 from this index so return ans
            if (nums[i] > 0) return ans;
            
            // initialize low and high from i + 1 th pos to end of array
            int low = i + 1;
            int high = nums.size() - 1;
            
            while (low < high) {
                
                // compute the current sum which we will be checking
                int current_sum = nums[i] + nums[low] + nums[high];
                
                // if sum is zero we found our triplet
                // push it into the ans 
                if (current_sum == 0) {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                    
                    // these condition will take care of repeated elements 
                    // so we do not get duplicate triplet in our ans 
                    while (low < high && nums[low-1] == nums[low]) low++;
                    while (low < high && nums[high+1] == nums[high]) high--;
                }
                
                // if sum > 0 we decrease right pointer
                else if (current_sum > 0) high--;
                // if sum < 0 we inc left pointer
                else low++;
                  
            }
            // increase i till it is not same as previous
            // as we have made all triplet possible from current i
            // so if nums[i] is repeated we do not want duplicate triplets
            i++;
            while (i < nums.size() && nums[i] == nums[i-1]) i++;
        }
        return ans;
    }
};
