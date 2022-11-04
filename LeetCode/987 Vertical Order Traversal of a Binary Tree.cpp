/**
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/solutions/2527028/leetcode-the-hard-way-easy-dfs-explained-line-by-line/
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
// USE COORDINATE GEOMETRY
// make map map of all nodes with their coordinates, use multiset for nodes as we need in inc order
// traverse in map and create ans 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;    // [x][y]{1,2,3} <- coordinates then mutiset of value
        dfs(root, 0, 0, nodes);                     // create nodes map from tree

        // for a 'x' we need all values in a vector (col)
        for (auto column : nodes) {
            
            vector<int> col;
            // iterate in 2nd map
            for (auto rows : column.second) {
                // insert all elements from multiset in col vector in its end using insert
                col.insert(col.end(), rows.second.begin(), rows.second.end());
            }
            // push col vector in ans
            ans.push_back(col);
        }
        return ans;
    }
    // dfs to store coordinates in maps and value in multiset
    // x axis -> outer map
    // y axis -> inner map
    // going to left dec x, right inc x
    // y++ whenever we go to next level
    void dfs(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>& nodes) {

        if (!root) return;
        nodes[x][y].insert(root -> val);

        dfs(root -> left, x - 1, y + 1, nodes);
        dfs(root -> right, x + 1, y + 1, nodes);
    }
};
