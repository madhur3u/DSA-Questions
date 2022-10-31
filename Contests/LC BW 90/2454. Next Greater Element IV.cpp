class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, -1);
        // use 3 stacks s2 will have those indices who have not found thier 2nd greater 
        // s1 will have indices as we do in nge, temp is use to transfer elements from s1 to s2
        stack<int> s1, s2, temp;    
        
        for (int i = 0; i < n; i++) {

            // if we found element greater than element in s2 top
            // means we have found a second greater element for ith index to be nums[i]
            // since we compare 1st nge in s1 stack and shift that index to s2, so current nums[i] will be 2nd ge
            while (!s2.empty() && nums[s2.top()] < nums[i]) {
                ans[s2.top()] = nums[i];
                s2.pop();
            }            
            // when we find 1st ge push the index in temp stack
            while (!s1.empty() && nums[s1.top()] < nums[i]) {
                temp.push(s1.top());
                s1.pop();
            } 
            // push all elements from temp to s2, we do this so index are stored in s2 as in s1 
            // if we directly push in s1 it will be stored in reverse manner
            while (!temp.empty()) {
                s2.push(temp.top());
                temp.pop();
            }
            // push current element to stack s1
            s1.push(i);
        }
        return ans;
    }
};
/*
Explanation

Use two stack s1 and s2.
Similar to "Next Greater Element"
s1 stores the index of elements
that have not found their first greater element.

s2 stores the index of elements
that have found their first greater element,
have not found their second greater element.

For each a = A[i] in A
We first compare the a with the tail elements in s2,
pop all element smaller than a,
because a is their second greater element.

Then we compare the a with the tail elements in s1,
move all elements smaller than a to the tail of s2,
because a is their first greater element.

We repeatly do this for all A[i] and finally return the result.
*/
