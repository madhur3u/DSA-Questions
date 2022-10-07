// https://takeuforward.org/data-structure/next-greater-element-using-stack/
// DRY RUN ONCE

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        // we store the next greater el in stack st, and ans in ans vector
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);

        // since we are given circular array so just double then array
        // join array once again after end, we dont need to make another array we can just do using i % n
        // till i < n  we form the next greater elements in stack so that end elements do not have -1 
        // for that we start pointer from 2*n-1 and dont push in ans till i < n
        for (int i = 2 * n - 1; i >= 0; i--){

            // this will check if element in stack are greater than current nums[i % n]
            // if not we pop them till this condition satisfy
            while (!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }
            // now when i < n
            // if stack empty means no greater element so push -1 
            // else push whatever in top of stack
            if (i < n) 
                ans[i] = !st.empty() ? st.top() : -1;
            
            // push the current element to stack
            st.push(nums[i % n]);
        }
        return ans;
    }
};
