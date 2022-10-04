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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        // base case when root numm return false
        if (!root) return false;

        // remove current node value from targetSum
        targetSum -= root -> val;

        // desired condition when sum = 0 and we are at leaf node
        if (!root -> left && !root -> right && targetSum == 0) return true;

        // traverse in both nodes and OR thier result
        return hasPathSum(root -> left, targetSum) || hasPathSum(root -> right, targetSum);
    }
};
