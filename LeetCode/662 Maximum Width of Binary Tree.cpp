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
// https://takeuforward.org/data-structure/maximum-width-of-a-binary-tree/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        if (!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;  // bfs q of node and index of that node in level
        q.push({root, 0});              // push 1st node and its index 0 in q

        while (!q.empty()){
            
            // we start indexinf from 0 to n in each level, if we give continous index it may cause int overflow
            int size = q.size();
            int cmin = q.front().second;    // we subtract the min index from each index in the level 
            int left, right;                // leftmost and rightmost indices in level

            for (int i = 0; i < size; i++) {

                TreeNode* curr = q.front().first;       // extract node
                int index = q.front().second - cmin;    // extract index 
                q.pop();
                
                if (i == 0)         left = index;       // leftmost index at i = 0
                if (i == size - 1)  right = index;      // right most idx at i = size - 1

                // push valid nodes with thier index in next level
                if (curr -> left)  q.push({curr -> left,  (long)2*index + 1});
                if (curr -> right) q.push({curr -> right, (long)2*index + 2});
            }
            ans = max(ans, right - left + 1);   // compute ans  
        }
        return ans;
    }
};
