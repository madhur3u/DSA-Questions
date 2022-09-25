// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    // global vector stores the result
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        // temp vector which stores combinations
        // call fn with initial index 0
        vector<int> c;
        findingCombinations(0, target, c, candidates);
        return res;
    }
    
    // this fn will find all the combinations recursively and push into res
    void findingCombinations(int index, int target, vector<int> &c, vector<int>& arr){
        
        // when all indexes checked we need to return
        // before that check if target has reached 0, means found a combination
        if (index == size(arr)){
            if (target == 0) res.push_back(c);
            return;
        }
        
        // TAKING THE CURRENT INDEX
        // case when we inclue the current index, push value in c
        // recursive call, reduce target but index remains same as we can take 1 index's value more than 1 time
        // remove the element when we are out of fn
        if (target >= arr[index]){
            c.push_back(arr[index]);
            findingCombinations(index, target - arr[index], c, arr);
            c.pop_back();
        }
        
        // NOT TAKING THE CURRENT INDEX
        // inc index do not change target
        findingCombinations(index + 1, target, c, arr);
    }
};
