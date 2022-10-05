class MyQueue {
public:
    stack <int> st, temp;
    MyQueue() {
    }
    
    // pop all elements from st stack and push in temp stack
    // now push x in st
    // push the elements from temp again to st this way the 1st pushed el will be at top
    void push(int x) {

        while (!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while (!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    
    // top el is first pushed element
    int pop() {
        if (st.empty()) return 0;

        int el = st.top();
        st.pop();
        return el;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
