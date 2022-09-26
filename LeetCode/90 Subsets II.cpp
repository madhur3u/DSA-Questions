// https://leetcode.com/problems/subsets-ii/
// Time: O(N * 2^N) since the recurrence is T(N) = 2T(N - 1) and we also spend at most O(N) time within a call.
// Space: O(N * 2^N) since there are 2^N subsets. If we only print the result, we just need O(N) space.

class Solution {
public:
    // stores result
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        // sorting to take care of duplicate combinations
        sort(begin(nums), end(nums));
        vector<int> c;
        findSB(0, c, nums);
        return res;
        
    }
    void findSB(int index, vector<int> &subset, vector<int>& arr){
    
        // BASE CASE
        // push subset to result and return
        if (index == arr.size()){
            res.push_back(subset);
            return;
        }
        
        // CASE 1 : TAKING THE CURRENT ELEMENT
        // inc index take the curren el in subset, pop when fn call end
        int num = arr[index++];
        subset.push_back(num);
        findSB(index, subset, arr);
        subset.pop_back();
        
        // CASE 2 : NOT TAKING CURRENT ELEMENT IN COMBINATION
        // inc the index till repititive elements to take care of duplicate subsets
        // as al combinations will be dealt with taking call
        // so place index in next diff element and call fn 
        while(index < size(arr) && arr[index] == num) index++;
        findSB(index, subset, arr);
    }
};
