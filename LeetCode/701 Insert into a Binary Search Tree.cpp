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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if (!root) return new TreeNode(val);    // if no tree
        TreeNode* curr = root;                  // store root in curr

        // inf loop
        while (1) {
            // if value to be added will be added in left side means node's val > val
            // check if left exist if exist change curr to curr -> left
            // if left no exist, insert node and break loop
            // SAME FOR RIGHT
            if (curr -> val > val) {
                if (curr -> left) curr = curr -> left;
                else {
                    curr -> left = new TreeNode(val);
                    break;
                }
            }
            else {
                if (curr -> right) curr = curr -> right;
                else {
                    curr -> right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }

};
