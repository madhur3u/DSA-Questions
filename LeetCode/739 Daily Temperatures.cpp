class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {

        int n = t.size();
        stack<int> st;   // monotonic stack store <element, index>

        // initially all 0, stores distance between their next greater element and current temperature
        vector<int> ans(n, 0);  

        // move from end to start and find nge
        for (int i = n - 1; i >= 0; i--) {

            // pop until we find next greater element to the right
            // since we came from right stack will have element from right only
            // s.top() is the index of elements so we put that index inside temperatures vector to check
            while (!st.empty() && t[st.top()] <= t[i]) 
                st.pop();
            
            // if stack not empty, then we have some next greater element, 
            // so we take distance between next greater and current temperature
            // as we are storing indexes in the stack
            if (!st.empty()) ans[i] = st.top() - i;     // distance between next greater and current
            
            // push the index of current temperature in the stack,
            // same as pushing current temperature in stack
            st.push(i);
        }   
        return ans;
    }
};
