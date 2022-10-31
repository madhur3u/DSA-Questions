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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        queue<TreeNode*> q;     // queue for BFS

        if (!root) return ans;  // checking if tree doesnt exist
        q.push(root);           // push the current root in queue
        
        // BFS APPROACH: till queue is empty
        while (!q.empty()) {

            // find size, make a temp vector which store all node vals in current level
            int size = q.size();
            vector<int> currLevel;

            // iterate for size times
            while (size--) {
                
                // extract the first node stored in queue, pop
                // push its val in currLevel
                TreeNode *temp = q.front(); q.pop();
                currLevel.push_back(temp -> val);

                // push left and right nodes of temp in queue if they exist
                if (temp -> left) q.push(temp -> left);
                if (temp -> right) q.push(temp -> right);
            }
            // push current level elements in ans
            ans.push_back(currLevel);
        }
        return ans;
    }
};
