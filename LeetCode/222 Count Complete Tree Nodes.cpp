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
// LOGN * LOGN
class Solution {
public:
    int countNodes(TreeNode* root) {
        
        if (!root) return 0;    // if tree doesnt exist
        return dfs(root);       // return no. of nodes from dfs
    }
    int dfs(TreeNode* root) {

        if (!root) return 0;    // BASE CASE    

        // h1 -> height of leftmost branch, h2 -> height of rightmost branch
        // find out heights of both branches, log(n)
        int h1 = 0, h2 = 0;     

        TreeNode* temp = root;
        while (temp)    
            temp = temp -> left, h1++;
        temp = root;
        while (temp)    
            temp = temp -> right, h2++;

        // in a complete tree / subtree, if h1 == h2 it means we have all nodes in that tree
        // so we use formula (2 ^ height) - 1 -> total no. of nodes from root
        if (h1 == h2) 
            return (1 << h1) - 1;

        // when height not same we rec call to both subtrees and add 1 in ans from dfs
        // since tree is complete we can find ans in log(n)
        return 1 + dfs(root -> left) + dfs(root -> right);
    }
};
/*
Let n be the total number of the tree. It is likely that you will get a child tree as a 
perfect binary tree and a non-perfect binary tree (T(n/2)) at each level.

T(n)= T(n/2) + c1 lgn
    = T(n/4) + c1 lgn + c2 (lgn - 1)
    = ...
    = T(1) + c [lgn + (lgn-1) + (lgn-2) + ... + 1]
    = O(lgn*lgn)   
*/
