// https://leetcode.com/problems/single-number/
// https://www.javatpoint.com/cpp-bitwise-xor-operator

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;
        
        // for all repeated(2 time occuring) elements bitwise xor will return 0
        // so our final andwer will only have the non repeated element after xoring all elements of array
        for (auto i : nums){
            ans = ans ^ i;
        }
        return ans;
        
    }
};

// solution using hashmap

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        // store number and frequency in map
        for (auto i : nums){
            mp[i]++;
        }
        
        // if freq is 1 return the number (key)
        for (auto it:mp){
            if (it.second == 1) return it.first;
        }
        return -1;
    }
};
