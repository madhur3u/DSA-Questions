/*
I have one input stack, onto which I push the incoming elements, and one output stack, from which I peek/pop. 
I move elements from input stack to output stack when needed, i.e., when I need to peek/pop but the output stack is empty. 
When that happens, I move all elements from input to output stack, thereby reversing the order so it's the correct order for peek/pop.

The loop in peek does the moving from input to output stack. 
Each element only ever gets moved like that once, though, and only after we already spent time pushing it, 
so the overall amortized cost for each operation is O(1).
*/

class MyQueue {
public:
    stack <int> input, output;
    MyQueue() {
    }
    // push always in input
    void push(int x) {
        input.push(x);
    }

    // call peek first to move all elements of input to output if output empty
    // remove top element of output
    int pop() {
        peek();
        int el = output.top();
        output.pop();
        return el;
    }
    
    // if output empty, mobe all elements from input to output this way we have fifo order in output
    // return top of output hich is front of queue
    // if output already had elements we just return the topmost element no shifting 
    int peek() {
        if (output.empty()){
            while (input.size()){
                output.push(input.top());
                input.pop();
            } 
        }
        return output.top();
    }
    
    // if both stack empty then only queue empty
    bool empty() {
        return input.empty() && output.empty();
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
