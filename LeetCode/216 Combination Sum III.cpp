// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    // stores result
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        
        // temp vector to store combination
        vector<int> c;
        // since the series of number is from 1 to 9 so sending initial number 1 in function
        findingCombinations(1, k, n, c);
        return res;
    }
    void findingCombinations(int num, int k, int sum, vector<int> &c){
        
        // BASE CASES
        // when no. of elements taken is == k, since we are subtracting so it will be zero
        // so we check if sum is 0, as we are subtracting each element so sum 0 when all k elements sum is n
        // we push comb in res and return
        if (k == 0){
            if (sum == 0) res.push_back(c);
            return;
        }
        // if sum < 0 no need to add more as it will dec sum more
        // if num > 9 out of range as constrain num range from 1 to 9
        if (sum < 0) return;
        if (num > 9) return;
        
        // CASE 1 : TAKING THE CURRENT ELEMENT IN COMBINATION
        // reduce k as we have taken a element, reduce sum by value of num
        // inc num for next combination, remove element from c when fn ends
        c.push_back(num);
        findingCombinations(num + 1, k - 1, sum - num, c);
        c.pop_back();

        // CASE 2 : NOT TAKING THE CURRENT ELEMENT IN COMBINATION
        // only inc num
        findingCombinations(num + 1, k, sum, c);
    }
};
