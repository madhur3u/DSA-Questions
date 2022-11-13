/**
https://www.youtube.com/watch?v=ZWGW7FminDM&t=793s

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

// find the two nodes which are not in place
// do inorder traversal keep track of prev node
// inorder traversal is sorted in BST so if any abnormal found update first, mid, last node accordingly
class Solution {
public:
    TreeNode *first, *prev, *middle, *last;

    void recoverTree(TreeNode* root) {
        
        if (!root) return;
        first = last = middle = nullptr;    // set all nodes to null
        prev = new TreeNode(INT_MIN);       // prev node set to min 
        inorder(root);                      // do the inorder traversal

        // if last exist means 2 abnormal values found, swap both of them
        if (last) swap(first -> val, last -> val);

        // if last doesnt exist and mid exist means only one abnormal value was found
        // it means the values to be swapped are adjacent so swap first and middle
        else if (middle) swap(first -> val, middle -> val);
    }

    void inorder(TreeNode* root) {

        if (!root) return;      // BASE CASE
        inorder(root -> left);  

        // if the value is abnormal in inorder traversal means it is < previous
        if (prev && prev -> val > root -> val) {

            // if this is the first abnormal node, means first will be null
            // update first and middle 
            if (!first) {
                first = prev;
                middle = root;
            }
            // if first was not null means 2nd abnormal value found, give it to last
            else last = root;
        }
        // update prev at each call
        prev = root;
        inorder(root -> right);
    }
};
