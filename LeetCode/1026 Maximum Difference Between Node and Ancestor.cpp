/**
https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/solutions/895566/maximum-difference-between-node-and-ancestor/
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
// DRY RUN
class Solution {
public:
    int dfs(TreeNode* node, int maxVal, int minVal) {

        // we keep max and mn val track and when we reach end of tree from leaf node
        // return the diff b/w max and min value
        if (!node) return abs(maxVal - minVal);

        // when we are in a node
        // update max and min value by comparing it to the curr node val
        maxVal = max(maxVal, node->val);
        minVal = min(minVal, node->val);

        // go to left and right dir and send the max min value
        int left  = dfs(node->left,  maxVal, minVal);
        int right = dfs(node->right, maxVal, minVal);

        // return the max of left and right
        return max(left, right);
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};
