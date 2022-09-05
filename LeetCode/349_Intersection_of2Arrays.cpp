// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        // using set as it store unique values
        // make set of array 1 
        unordered_set <int> st;
        for (int i : nums1){
            st.insert(i);
        }
        
        // this will hold intersection
        vector<int> ans;
        
        // in second array traverse and check if the el present in set
        // if present push it in the ans vector
        // and delete that el from set to take care of repitition
        for (int i : nums2){
            if (st.find(i) != st.end()){
                ans.push_back(i);
                st.erase(i);
            }
        }
        
        return ans;
    }
};
