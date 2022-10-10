class Solution {
public:
    // we are going to compute area for each rectangle
    // for that we need its prev and next min
    // area will be (prev - next)distance * a[i]
    // and like that we wil compute for each value and find max
    int largestRectangleArea(vector<int>& h) {
        
        // finding next and prev min using inc monotonic stack
        stack<int> st;
        int res = 0, n = h.size();

        for (int i = 0; i <= n; i++) {

            // when a element at i is less than top of stack, we can say that ith element is next min
            // for the top element of stack and the value below stack,s top will be prev min
            // since we are storing indices in stack so we can calculate width using those
            // and compute the area for the stack.top() element 
            // i == n case when all height are taken but stack is still not empty
            // we need to compute ans for those heights also
            // for them the next min index == n as they will dont have next min
            // for el not having prev min use -1   
            while (!st.empty() && (i == n || h[st.top()] > h[i])) {

                int currIndex = st.top(); st.pop();
                int nextIndex = i;
                int prevIndex = (st.empty()) ? -1 : st.top();

                // computing area and comparing with prev max res stored
                res = max(res, h[currIndex]*(nextIndex - prevIndex - 1));
            }
            // push element in stack after above computation
            st.push(i);
        }
        return res;
    }
};
