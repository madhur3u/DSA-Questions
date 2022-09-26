// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    // stores result
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        // sorting to take care of duplicate combinations
        sort(begin(nums), end(nums));
        vector<int> c;
        findingCombinations(0, target, c, nums);
        return res;
    }
    void findingCombinations(int index, int target, vector<int> &c, vector<int>& arr){
    
        // WHEN WE FOUND A COMBINATION
        // push combination to result and return
        if (target == 0){
            res.push_back(c);
            return;
        }
        
        // BASE CASE, when out of index or target below zero
        if (index == size(arr) || target - arr[index] < 0) return;
        
        // CASE 1 : TAKING THE CURRENT ELEMENT IN COMBINATION
        // inc index, and push num in c, subtract num from target and send to recusrive call
        // remove num when call ends
        int num = arr[index++];
        c.push_back(num);
        findingCombinations(index, target - num, c, arr);
        c.pop_back();
        
        // CASE 2 : NOT TAKING CURRENT ELEMENT IN COMBINATION
        // in this 1st we need to check if repititive of num occurs
        // inc index till same num is found, or array ends, send the index of diff num in recursive call
        //    [1,1,1,1,2,3,4,5]                                       [1,1,1,1,2,3,4,5]
        // num | | index was here, same as num, so we inc and place index here |
        while(index < size(arr) && arr[index] == num) index++;
        findingCombinations(index, target, c, arr);
    }
};
