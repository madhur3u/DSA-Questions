// https://leetcode.com/problems/path-sum-ii/
/*
Depth-first search

DFS (Depth-first search) is technique used for traversing tree or graph. Here backtracking is used for traversal. 
In this traversal first the deepest node is visited and then backtracks to it’s parent node if no sibling of that 
node exist. 

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
    // global 2d vector to store ans
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        // make a temp vector path which store path's value stored till now in tree
        // and this path will be pushed in ans when sum = targetSum;
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
    }
    
    // reursive call fn 
    void dfs(TreeNode *root, int sum, vector<int> &path){
        
        // base case when node doesnt exist
        if (root == nullptr) return;
        
        // push current path's value to path vector
        // update the sum by subtacting value of current node
        path.emplace_back(root -> val);
        sum = sum - (root -> val);
        
        // CONDITION SATISFIED
        // when we reach leaf node and sum ==0
        // since we are subtracting sum with value in each node, so if sum 0 means we found 
        // a root-to-leaf path with sum equal targetSum so push this path into ans
        if (root -> left == nullptr && root -> right == nullptr && sum == 0)
            ans.push_back(path);
        
        // when not leaf node go to left and right node recursively
        // in case of leaf node its going to be null so return from base case
        dfs(root -> left, sum, path);
        dfs(root -> right, sum, path);
        
        // pop the element back which was pushed as we are leaving this root node now when fn execute this line
        path.pop_back();
    }
};
