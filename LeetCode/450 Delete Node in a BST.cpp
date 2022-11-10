/**
https://leetcode.com/problems/delete-node-in-a-bst/solutions/1591176/c-simple-solution-w-images-detailed-explanation-iterative-recursive-approach/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        // STEP 1 : FIND THE NODE TO BE DELETED AND ITS PARENT
        // node can be found using simple binary search and store parent also 
        TreeNode *node = root, *node_parent = nullptr;
        while(node && node -> val != key){
            node_parent = node;
            if (node -> val > key) node = node -> left;
            else node = node -> right;
        }
        if (!node) return root;     // if node not found return root, nothing to delete

        // STEP 2 : NODE FOUND, BUT IT HAS NO CHILD OR ONLY ONE CHILD
        if (!node -> left || ! node -> right) {
          
            TreeNode* child = node -> left ? node -> left : node -> right;          // extract child
          
            if (!node_parent)                       root = child;                   // when we have to delete root, no parent of node exist
            else if (node_parent -> left == node)   node_parent -> left = child;    // if left has to be deleted
            else                                    node_parent -> right = child;   // if right has to be deleted
        }
        // NODE FOUND BUT HAS BOTH CHILD NODES
        else {
            TreeNode* temp = node;                      // store node to be deleted in temp
            node_parent = node, node = node -> right;   // we will be finding smallest el in right subtree
            
            // smallest element in right subtree will be its leftmost element
            while (node -> left) {
                node_parent = node;
                node = node -> left;
            }
            // now node will be at the smallest node in right subtree of node to be deleted
            // swap values of node to be del and this node
            temp -> val = node -> val;

            // smallest node replaced from right subtree may have a right child. 
            // So update that node's parent to hold the right child
            if (node_parent -> left == node) node_parent -> left  = node -> right;
            else                             node_parent -> right = node -> right; 
        }
        delete node;
        return root;
    }
};
