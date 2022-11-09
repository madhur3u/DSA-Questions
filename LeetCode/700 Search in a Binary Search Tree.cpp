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
// binary search in tree
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if (!root) return nullptr;                  // BASE CASE

        if (root -> val == val)                     // val found return node
            return root;
        else if (root -> val > val)                 // if root val is greater val will be in left subtree
            return searchBST(root -> left, val);
        else                                        // else val will be in right subtree
            return searchBST(root -> right, val);
    }
};
