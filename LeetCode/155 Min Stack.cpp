class MinStack {
public:
    stack <pair<int, int>> st;

    MinStack() {    
    }

    // we make a pair stack where 1st value store val and second store min so far <val, min>
    // when st empty, both val and min be same 
    // when puhing other elements we compare the val with previous min and store the minimum
    void push(int val) {
        if (st.empty()) st.push({val, val});
        else            st.push({val, min(val, st.top().second)});
    }
    
    // just pop top
    void pop() {
        st.pop();
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
