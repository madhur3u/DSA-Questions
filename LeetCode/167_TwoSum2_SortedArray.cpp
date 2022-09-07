// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        
        vector<int> ans;
        
        // using two poimter approach set both pointers at start and end point of array
        int i = 0, j = a.size() - 1;
        
        // run loop till both pointer pass each other or at same point
        while (i < j){
            
            // compute the current sum of el directed by pointers
            int current_sum = a[i] + a[j];
            
            // if sum = target, push indices in ans and return ans
            if (current_sum == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            
            // if sum > target since array is sorted so to decrease our sum we have to shift j leftwards
            // so we decrease the right pointer j
            else if (current_sum > target) j--;
            
            // if sum < target means we have to increase our sum so shift left pointer rightwards i.e. i++
            else i++;
        }
        return ans;
    }
};
