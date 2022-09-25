// https://leetcode.com/problems/find-all-good-indices/

class Solution {
public:
    vector<int> goodIndices(vector<int>& a, int K) {
        
        int n = a.size();
        
        // we make prefix / suffix array which will store the no. non inc and non dec elements for a given index
        vector<int> non_inc(n,1),non_dec(n,1),ans;
        
        // prefix array
        // making array for non-inc numbers from front
        // this array will have at index the length of non inc subarray found till that index
        // [2 1 1 1 3 4 1]
        // [1 2 3 4 1 1 2] non_inc array
        for (int i = 1; i < n; i++){
            if (a[i - 1] >= a[i]) 
                non_inc[i] = non_inc[i - 1] + 1;
        }
        // suffix array
        // making array for non-dec numbers from back
        // this array will have at index the length of non dec subarray found from that index till end
        // [2 1 1 1 3 4 1]
        // [1 5 4 3 2 1 1] non_dec array
        for (int i = n - 2; i >= 0; i--){
            if (a[i] <= a[i + 1]) 
                non_dec[i] = non_dec[i + 1] + 1;
        }
        
        // now we will traverse from K to n-K index
        // and check for inc dec subarray lengths at index before and after k
        // the subarray length should be >= k for that index to be a good index
        for (int k = K; k < n - K; k++){
            if (non_inc[k -1] >= K && non_dec[k + 1] >= K) 
                ans.push_back(k);
        }
        return ans;
    }
};
