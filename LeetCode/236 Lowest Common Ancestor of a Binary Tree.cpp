/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // base case, when root null or any of the node to check is equal to root, we return root
        if (!root || root == p || root == q) return root;

        TreeNode* left  = lowestCommonAncestor(root -> left,  p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if (!left)          return right;   // left null or both null
        else if (!right)    return left;    // left not null and right null case
        else                return root;    // when both not null we return root, current node
    }
};
