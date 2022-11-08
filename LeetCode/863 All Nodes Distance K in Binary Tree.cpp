/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;     // this will map all children with parents
    unordered_set<TreeNode*> visited;               // set to hold nodes we visited
    vector<int> ans;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if (!root) return ans;  // tree doesnt exist
        
        makeParentMap(root);    // make map with all children -> parent link using map
        dfs(target, k);         // now from target we travel 2 distance to all 3 pos left right and parent 
        return ans;
    }
    // to make childre -> parent link in map
    void makeParentMap(TreeNode* root) {

        if (!root) return;
        if (root -> left) {
            parent[root -> left] = root;
            makeParentMap(root -> left);
        }
        if (root -> right) {
            parent[root -> right] = root;
            makeParentMap(root -> right);
        }
    }
    // from target move k steps to all 3 dir in dfs
    void dfs(TreeNode* node, int k) {

        if (!node) return;                                  // BASE CASE
        if (visited.find(node) != visited.end()) return;    // invalid case, node was already visited
        
        visited.insert(node);   // insert node in set

        // if we have moved k steps, current node val will be at k dist so push in ans and return
        if (k == 0) {
            ans.push_back(node -> val);
            return;
        }
        // all 3 calls, decrease k
        dfs(node -> left, k - 1);
        dfs(node -> right, k - 1);
        dfs(parent[node], k - 1);
    }
};
