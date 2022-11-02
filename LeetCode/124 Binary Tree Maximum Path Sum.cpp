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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;  // initialise ans
        dfs(root, ans);     // call fn
        return ans;
    }
    int dfs(TreeNode* root, int& ans) {

        if (!root) return 0;    // base case

        // left rec call will give us max left sum, we max i with 0 to avoid negetive ans
        // if the value is negetive we wont consider the path as sum has to be maximised
        int left_sum = max(0, dfs(root -> left, ans));  
        
        // doing same for right path
        int right_sum = max(0, dfs(root -> right, ans));
        
        // form the max sum at current node using left_sum + right_sum + root -> val
        // compare with already store ans, maximise ans
        ans = max(ans, left_sum + right_sum + root -> val);

        // we are going to return the max path sum at current node so we take max from left and right + val
        return max(left_sum, right_sum) + root -> val;
    }
};
/*
https://takeuforward.org/data-structure/maximum-sum-path-in-binary-tree/

    Initialize a maxi variable to store our final answer.
    Do a simple tree traversal. At each node, find  recursively its leftMaxPath and its rightMaxPath.
    Calculate the maxPath through the node as val + (leftMaxPath + rightMaxPath) and update maxi accordingly.
    Return the maxPath when node is not the curving point as val + max(leftMaxPath, rightMaxPath).
*/
