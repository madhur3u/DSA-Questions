// https://leetcode.com/problems/two-sum/
// https://www.youtube.com/watch?v=KLlXCFG5TnA

// Approach: We can solve this problem efficiently by using hashing. 
// We’ll use a hash-map to see if there exists a value target – x for each value x. 
// If target – x is found in the map, can return current element x’s index and (target-x)’s index

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        
        // this map store value and indexes of each element of array
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for (int i = 0; i<a.size(); i++){
            
            // if we find the diff b/w the target and current element in map
            // means we got the second element
            // so push indices to ans
            if (mp.find(target - a[i]) != mp.end()){
                ans.push_back(mp[target-a[i]]);
                ans.push_back(i);
            }
            
            // if not found push value : index pair in map
            // we are pushing in end as since we search for diff so 
            // even if its the last value in array we will already have the pair stored in hashmap
            // also this takes care of taking one element twice problem
            mp[a[i]] = i;
        }
        return ans;
    }
};
