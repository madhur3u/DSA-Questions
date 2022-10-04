// https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

//Function to push an integer into the stack.
void MyStack ::push(int x) {
    // make a new node with x as data
    StackNode *st = new StackNode(x);
    
    // set this node as first element of ll
    // so we are actually putting elements in 1st pos so that pop is easy
    // update top to the new element node st
    st -> next = top;
    top = st;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() {
    // if top null means no element in stack
    if (!top) return -1;
    
    // make tempnode as top
    // move top to next place, return data stored in temp and delete temp
    StackNode *temp = top;
    
    top = top -> next;
    int x = temp -> data;
    delete(temp);
    return x;
}
