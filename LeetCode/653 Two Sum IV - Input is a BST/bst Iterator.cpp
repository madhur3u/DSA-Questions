/**
https://www.youtube.com/watch?v=ssL3sHwPeb4&t=372s

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

// make bst iterator which can make iterator from front and from reverse
// for rerverse we will use bool value and do opposite of what we do for next
// no need to change variable
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;           // this variable will tell if we are looking for before(false) or next value

    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        push_all(root);
    }
    
    // change in next, when reverse is false we push all using node -> left
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (!reverse) push_all(node -> left);
        else          push_all(node -> right);
        return node -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    // change in push all
    // when reverse false, push all right nodes, reverse of what we do in next
    void push_all(TreeNode* node) {
        while (node) {
            st.push(node);
            if (!reverse) node = node -> right;
            else          node = node -> left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        if (!root) return false;
        BSTIterator l(root, true);      // left pointer 
        BSTIterator r(root, false);     // right pointer

        int i = l.next();               // 1st value from left
        int j = r.next();               // 1st value from right

        // do just like two sum in sorted array, we do -- and ++ using .next()
        while (i < j) {
            if (i + j == k)         return true;
            else if (i + j > k)     j = r.next();
            else                    i = l.next();
        }
        return false;
    }
};
