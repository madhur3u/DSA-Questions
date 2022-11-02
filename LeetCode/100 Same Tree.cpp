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

// RECURSIVE SOLN : DFS
class Solution {
public:
    bool isSameTree(TreeNode* q1, TreeNode* q2) {
        
        // base case when both null
        if (!q1 && !q2) return true;   

        // if only 1 is null return true, tree not same, same for values                        
        else if (!q1 || !q2) return false;                  
        else if (q1 -> val != q2 -> val) return false;       

        // make call to left for both nodes, and do same for right nodes
        // we && the result to get ans as if any one is false tree wont be same
        return isSameTree(q1 -> left, q2 -> left) && isSameTree(q1 -> right, q2 -> right);
    }
};


// ITERATIVE SOLUTION USING BFS
class Solution { 
public:
    bool isSameTree(TreeNode* P, TreeNode* Q) {
        
        queue<TreeNode*> q; // single q
        q.push(P);          // push both roots
        q.push(Q);

        while (!q.empty()) {

            // pop front 2 nodes and compare them they sould be same for tree to be same
            TreeNode* q1 = q.front(); q.pop();
            TreeNode* q2 = q.front(); q.pop();

            if (!q1 && !q2) continue;                           // both null
            else if (!q1 || !q2) return false;                  // if only 1 is null return false
            else if (q1 -> val != q2 -> val) return false;      // return false if val of both are diff

            q.push(q1 -> left);     // push the left el of q1
            q.push(q2 -> left);     // push left el of q2, smae for right

            q.push(q1 -> right);
            q.push(q2 -> right);
        }
        return true;    
    }
};
