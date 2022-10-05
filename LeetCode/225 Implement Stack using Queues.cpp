/*
Take a single queue.
push(x): Push the element in the queue.
Use a for loop of size()-1, remove element from queue and again push back to the queue,0 
hence the most recent element becomes the most former element and vice versa.
*/

class MyStack {
public:
    // queue to implement stack
    queue <int> q;
    MyStack() {
    }
    
    // in push we push the element in queue and take length of q before pushing
    // we pop the front element and push it in back of our queue n times
    // so after n operations 'x' will be in front of queue 
    // push -> O(n)
    void push(int x) {     
        
        int n = q.size();
        q.push(x);

        while (n--){
            q.push(q.front());
            q.pop();
        }
    }
    
    // front element is the topmost element of stack so pop front
    int pop() {
        int el = q.front();
        q.pop();
        return el;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
