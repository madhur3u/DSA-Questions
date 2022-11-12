/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;                // stack to store all left elements for a node
    BSTIterator(TreeNode* root) {
        push_all(root);                 // initiate : push all left elements and root in stack O(h)
    }
    
    int next() {
        TreeNode* node = st.top();      // top el of stack will be the min el so that will be next
        st.pop();                       // pop that
        push_all(node -> right);        // if node has right we push all elements from right left in st
        return node -> val;             // return curr node val
    }
    
    bool hasNext() {
        return !st.empty();             // if stack has elements then only next is possible else false
    }

    void push_all(TreeNode* node) {     // making stack
        while (node) {                  // while node exist push it in stack
            st.push(node);
            node = node -> left;        // go to the left till reach null, this wal all left el will be pushed
        }
    }
};

/*
Step 1: We will push the left part of the tree into a stack which is 7 and then 3 is inserted. 
Now is next() is called 3 is stored as the top and then poped now we will push the right of 3 but it 
does not contain any so we just return the top->val i.e. 3.

Step 2: We will now pop() 7 from the stack and see if it has the right children yes it has so we push 15 
and then 9 into the stack. Observe here you'll see at a time stack contains elements equal to the height 
of the tree.

Step 3: Now 9 is poped and 9 does contain any right child so we move on 15. If hasnext() is called it 
would return true as traversal is still left and the stack is also not empty.

Step 4: Now 15 is poped and checked if it has the right child yes it has i.e. 20 so 20 is pushed inside 
the stack.

Step 5: Lastly 20 is poped and returned and after that is hasnext() is called it will return false as 
there are no more elements or children inside the stack.
*/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
