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
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
    int dfs(TreeNode* root) {
        // base case
        if (!root) return 0;

        // find out left and right heights
        int left_height = dfs(root -> left);
        int right_height = dfs(root -> right);

        // if any of the left or right height has -1, which could have been returned from a fn where diff is > 1
        // we return -1 so no extra traversal is done
        if (left_height == -1 || right_height == -1) return -1;

        // invalid condition for balanced tree
        if (abs(left_height - right_height) > 1)     return -1;

        // returning height of tree
        return max(left_height, right_height) + 1;
    }
};

/*CODE TO FIND THE HEIGHT OF TREE USING DFS
we find the left and right height and take maximum 
+1 to consider the root

so when we calculated left and right height we will check at that time if abs(left_height - right_height) > 1
this will tellus if tree is balanced or not, we return -1 in that case
    int dfs(TreeNode* root) {

        if (!root) return 0;

        int left_height = dfs(root -> left);
        int right_height = dfs(root -> right);

        return max(left_height, right_height) + 1;
    }
*/
