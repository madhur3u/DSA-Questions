/**
https://leetcode.com/problems/kth-smallest-element-in-a-bst/solutions/1960046/multiple-c-solutions-with-explanations-time-complexity/

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
// do inorder traversaltill kth element is reached
// inorder traversal of bst will give us nodes in sorted order
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        int ans;
        inorder(root, k, ans);
        return ans;   
    }
    // inorder traversal fn
    void inorder(TreeNode* root, int& k, int& ans) {

        if (!root || k <= 0) return;        // base case or k <= 0 when we have already found ans
        inorder(root -> left, k, ans);      // left call
        if (--k == 0) {                     // check if we are at kth element
            ans = root -> val;              // if yes store ans and return
            return;
        }
        if (!k) return;                     // if el already found return, no need to do right traversal
        inorder(root -> right, k, ans);     // right call
    }
};
