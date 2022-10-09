class Solution {
public:
    vector<int> findArray(vector<int>& pref) {

        // if a^b = c than b = a^c
        // this property is used here
        
        int n = pref.size();
        vector<int> ans(n);
        ans[0] = pref[0];
        
        for (int i = 1; i < n; i++){
            ans[i] = (pref[i - 1] ^ pref[i]); 
        }
        return ans;
    }
};
