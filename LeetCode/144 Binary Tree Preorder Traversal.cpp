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
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if (!root) return ans;

        // root, left, right
        // stack will have the elements in order of preorder traversal, initially put root
        stack<TreeNode*> st;
        st.push(root);

        // run till stack empty
        while (!st.empty()) {
            
            // extract top el and pop
            TreeNode* temp = st.top(); st.pop();

            // push the current el in ans
            ans.push_back(temp -> val);

            // push the right & left node in stack if exist, so when we traverse for next iteration
            // we will come across left first since we push it last, so our preorder is maintained
            if (temp -> right) st.push(temp -> right);
            if (temp -> left) st.push(temp -> left);
        }
        return ans;
    }
};
