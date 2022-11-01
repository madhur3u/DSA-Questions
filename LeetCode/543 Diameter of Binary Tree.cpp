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
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    // program to find height of the tree, modified to get diameter
    // compute lh and rh
    // calculate diameter
    int dfs(TreeNode* root, int& ans) {

        if (!root) return 0;

        int left_height = dfs(root -> left, ans);
        int right_height = dfs(root -> right, ans);

        ans = max(ans, left_height + right_height); // diameter

        return max(left_height, right_height) + 1;
    }
};

/*
The question can be solved by small modification to program of Height of tree.
The idea is quite simple. Max value of Height(leftSubtree)+Height(rightSubtree) (at any node ) is the diameter. 
Keep track of maxium diameter duing traversal and find the height of the tree.


*/
