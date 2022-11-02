// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0
// https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/

/*
Approach: Boundary traversal in an anti-clockwise direction can be described as a traversal consisting of three parts:

    Part 1: Left Boundary of the tree (excluding the leaf nodes). (push in ans while traversing)
    Part 2: All the leaf nodes travelled in the left to right direction. (simple dfs, pre order traversal)
    Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction. (using stack)
*/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    
    // start from root -> left, check if root exist and is not leaf node
    // push root value in ans, go to left if exist esle to right
    void left_boundary(Node* root, vector<int>& ans) {

        root = root -> left;
        while (root && (root -> left || root -> right)) {
            ans.push_back(root -> data);
            root =  (root -> left) ? root -> left : root -> right;
        }
    }
    // same as left but rather than pushing directly to ans we push it to a stack
    // after whole right traversal we add all elements in ans from top to bottom
    void right_boundary(Node* root, vector<int>& ans) {
        
        stack<int> s;
        root = root -> right;
        
        while (root && (root -> left || root -> right)) {
            s.push(root -> data);
            root =  (root -> right) ? root -> right : root -> left;
        }
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
    }
    // leaf node push directly to ans, pre order traversal
    void leaf_nodes(Node* root, vector<int>& ans) {
        if (!root -> left && !root -> right) 
            ans.push_back(root -> data);
            
        if (root -> left) leaf_nodes(root -> left, ans);
        if (root -> right) leaf_nodes(root -> right, ans);
    }
    
    vector <int> boundary(Node *root) {
        
        vector<int> ans;
        if (!root) return ans;  // if tree does not exist
        
        // push the root value to ans, 1st value
        if (root -> left || root -> right) ans.push_back(root -> data);
        
        // calling all 3 fns
        left_boundary(root, ans);
        leaf_nodes(root, ans);
        right_boundary(root, ans);
        
        return ans;
    }
};
