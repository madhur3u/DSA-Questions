/*
Key observation:
Suppose we have a decreasing sequence followed by a greater number
For example [5, 4, 3, 2, 1, 6] then the greater number 6 is the next greater element for all 
previous numbers in the sequence

We use a stack to keep a decreasing sub-sequence, whenever we see a number x greater than stack.top() we pop all elements less than x 
and for all the popped ones, their next greater element is x
For example [9, 8, 7, 3, 2, 1, 6]
The stack will first contain [9, 8, 7, 3, 2, 1] and then we see 6 which is greater than 1 so we pop 1 2 3 whose next greater element should be 6

initially we map each element to -1 then we change if we found a greater in while loop
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        // map for mapping each element
        // stack to store greater elements, res for ans
        unordered_map<int, int> mp;
        stack<int> st;
        vector<int> res;

        // iterate in nums2 to form map initially map element to -1 means no next greater element
        for (int el : nums2){
            mp[el] = -1;

            // if the el > topmost element than this el will be the next greater for st.top
            // so update map and pop the topmost element
            // do this till the while condition is true
            while (!st.empty() && el > st.top()){
                mp[st.top()] = el;
                st.pop();
            }
            // push el to stack
            st.push(el);
        }
    
        // we will map all elements in above loop so just push the val of map for each el in nums1
        for (int i : nums1) res.push_back(mp[i]);    
        return res;
    }
};
