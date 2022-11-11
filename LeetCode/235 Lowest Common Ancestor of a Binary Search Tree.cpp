/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int small = min(p -> val, q -> val);    // small and large vals
        int large = max(p -> val, q -> val);

        while (root) {

            if (root -> val > large)        root = root -> left;    // cant be in right subtree
            else if (root -> val < small)   root = root -> right;   // cant be in left subtree
            else 
                return root;    // curr val is b/w small and large so this will be the LCA
        }
        return nullptr;
    }
};
/*
Iterate in BST

    Let large = max(p.val, q.val), small = min(p.val, q.val).
    We keep iterate root in our BST:
        If root.val > large then both node p and q belong to the left subtree, go to left by root = root.left.
        If root.val < small then both node p and q belong to the right subtree, go to right by root = root.right.
        Now, small <= root.val <= large the current root is the LCA between q and p.

*/
