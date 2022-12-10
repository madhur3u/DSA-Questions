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
Firstly, we dfs to calculate the total sum of all nodes in the Binary Tree.
Then, we dfs in post order to calculate sum of each sub-tree in the Binary Tree.

    If the sum of current sub-tree is currSum, then its complement is totalSum - currSum.
    We update the answer if currSum * (totalSum - currSum) is greater than current answer.

Time: O(N), where N <= 5*10^4 is the number of nodes in the Binary Tree.
Space: O(H), where H is the height of the Binary Tree, it's the stack depth of the recursion. 
 */
class Solution {
public:
    long totalSum = 0, ans = 0;

    // find total sum of tree
    int treesum(TreeNode* root) {

        if (!root) return 0;
        return (root -> val) + treesum(root -> left) + treesum(root -> right);
    }
    // fn to split acc to problem
    // we need to find left sum of tree at each node --> currSum
    // right sum will be --> (totalSum - currSum)
    // find product at each node --> currSum * (totalSum - currSum)
    // maximise ans 
    int splitBT(TreeNode* root) {

        if (!root) return 0;
        int currSum = (root -> val) + splitBT(root -> left) + splitBT(root -> right);
        ans = max(ans, currSum * (totalSum - currSum));
        return currSum;
    }
    int maxProduct(TreeNode* root) {
        
        totalSum = treesum(root);       // find tree sum
        splitBT(root);                  // find max product by splitting
        return ans % (int)(1e9 + 7);    // return ans mod
    }
};
