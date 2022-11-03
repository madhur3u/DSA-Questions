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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return symmetry(root -> left, root -> right);
    }
    bool symmetry(TreeNode* r1, TreeNode* r2) {
        
        // checking nulls, if one is null 2nd should also be null
        if (!r1 || !r2) return r1 == r2;

        // fow symmetry value should be same for both nodes
        // send left and right in recursive call as we need to check irroe image and && them
        return (r1 -> val == r2 -> val) && 
                symmetry(r1 -> left, r2 -> right) && 
                symmetry(r1 -> right, r2 -> left);
    }
};
/*
The algorithm steps can be summarized as follows::

    We take two variables root1 and root2 initially both pointing to the root.
    Then we use any tree traversal to traverse the nodes. We will simultaneously change root1 and root2 in this traversal function.
    For the base case, if both are pointing to NULL, we return true, whereas if only one points to NULL and other to a node, we return false.
    If both points to a node, we first compare their value, if it is the same we check for the lower levels of the tree.
    We recursively call the function to check the root1’s left child with root2’s right child; then we again recursively check the root1’s right child with root2’s left child.
    When all three conditions ( node values of left and right and two recursive calls) return true, we return true from our function else we return false.
*/
