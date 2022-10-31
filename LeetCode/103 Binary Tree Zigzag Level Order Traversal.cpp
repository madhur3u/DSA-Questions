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

/*
we print levels just like normal bfs traversal, we just need to reverse every alternate level
extract level in ans, make a bool variavle which will tell us if we need to reverse current level vector
*/ 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        queue<TreeNode*> q;       // queue for BFS

        if (!root) return ans;    // checking if tree doesnt exist
        q.push(root);             // push the current root in queue
        bool lefttoright = true;  // this will tell us if we need to push current level in order or reverse
        
        // BFS APPROACH: till queue is empty
        while (!q.empty()) {

            // find size, make a temp vector which store all node vals in current level of size
            int size = q.size();
            vector<int> currLevel(size);

            // iterate for size times
            for (int i = 0; i < size; i++) {
                
                // extract the first node stored in queue, pop
                TreeNode *temp = q.front(); q.pop();

                // find the index acc to hoe we need to print this level
                // if falg is true means we need to print from left to right so index will be i
                // else in reverse printing we push values in reverse order in currlevel, when flag false
                int index = (lefttoright) ? i : (size - i - 1); 
                currLevel[index] = temp -> val;

                // push left and right nodes of temp in queue if they exist
                if (temp -> left) q.push(temp -> left);
                if (temp -> right) q.push(temp -> right);
            }
            // change flag for next iteration
            lefttoright = !lefttoright;
            ans.push_back(currLevel);
        }
        return ans;
    }
};
