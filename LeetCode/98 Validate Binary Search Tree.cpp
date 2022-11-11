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
class Solution {
public:
    // do inorder traversal
    // take prev initially to null else the prev node
    // at every point root > prev if not return false
    bool isValidBST(TreeNode* root) {
        
        TreeNode* prev = nullptr;
        return inorder(root, prev);
    }
    bool inorder(TreeNode* root, TreeNode* &prev) {     // & the prev

        if (!root) return true;     // BASE CASE

        // checking in left, if return value is false return false
        if (!inorder(root -> left, prev)) return false;
        
        // inorder checking
        // if prev exist and is >= root, means tree not BST, return false
        // else give current value to prev
        if (prev != nullptr && prev -> val >= root -> val) return false;
        prev = root;

        // check right and return whatever is returned
        return inorder(root -> right, prev);
    }
};
