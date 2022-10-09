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
    // set to store node val's like in 2sum
    unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        
        // base case
        if (!root) return false;

        // true case when pair found return true
        // else insert current node val to set and call again
        if (s.count(k - root -> val)) return true;
        s.insert(root -> val);

        return findTarget(root -> left, k) || findTarget(root -> right, k);
    }
};
