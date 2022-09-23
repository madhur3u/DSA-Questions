// https://practice.geeksforgeeks.org/problems/reverse-a-stack/1
/*
https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
Follow the steps mentioned below to implement the idea:

    Create a stack and push all the elements in it.
    Call reverse(), which will pop all the elements from the stack and pass the popped element to function insert_at_bottom()
    Whenever insert_at_bottom() is called it will insert the passed element at the bottom of the stack.
    Print the stack 
*/
class Solution{
public:
    
    // insert val at bottom of stack in this fn
    void insert_at_bottom(stack<int> &s, int val){
        
        // when stack empty push val // base case
        if (s.empty()){
            s.push(val);
            return;
        } 
        // when stack not empty, pop topmost el and store in temp
        // call fn recursively and push temp again
        int temp = s.top();
        s.pop();
        insert_at_bottom(s, val);
        s.push(temp);
    }
    
    // backtracking - reverse by popping till stack empty 
    // then push at bottom usingg other fn
    void reverse(stack<int> &s){
        
        if (s.empty()) return;
        
        int val = s.top();
        s.pop();
        reverse(s);
        insert_at_bottom(s, val);
    }
    
    // main
    stack<int> Reverse(stack<int> s){
        
        reverse(s);
        return s;
    }
};
