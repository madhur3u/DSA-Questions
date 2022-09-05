// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        // since weneed to keep track of repeated el also
        // so make a map with freq as values and el as keys
        unordered_map <int, int> mp;
        for (int i : nums1){
            mp[i]++;
        }
        
        vector<int> ans;
        
        // so if el exist in map we check if its freq > 0
        // if yes then push it in ans and decrease the freq 
        // this way we will get el we need in intersection
        for (int i : nums2){
            if (mp[i] > 0){
                ans.push_back(i);
                mp[i]--;
            }
        }
        
        return ans;
    }
};
