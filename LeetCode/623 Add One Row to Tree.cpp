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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        // when root does'nt exist
        if (!root) return nullptr;

        // if depth 1 we need to make new node as root and to its left will be our prev root
        // right will be null
        if (d == 1) 
            return new TreeNode(v, root, nullptr);

        // when depth is 2 we need to place node just after root
        // so we place the new node to the left and right side of root
        // the prev left and prev right will be with new left and right
        // other pointer in new node will be null
        if (d == 2){
            root -> left = new TreeNode(v, root -> left, nullptr);
            root -> right = new TreeNode(v, nullptr, root -> right);
            return root;
        }
        // if d > 2, using DFS go to next node both left and right using two calls
        // decrease depth for next call so that we know when to add newnode, when d == 2
        // we do not taking any return value from these as original root of tree wont be changed
        // we are changing in between tree
        addOneRow(root -> left, v, d - 1);
        addOneRow(root -> right, v, d - 1);

        return root;
    }
};
