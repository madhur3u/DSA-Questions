// https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/
// https://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/

#include <bits/stdc++.h>
using namespace std;

// defining tree
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode (int data) {
        this -> val = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// fn to print tree in IN ORDER TRAVERSAL FORM
void inOrderTraversal(TreeNode* root) {
    if (!root) return;
    inOrderTraversal(root -> left);
    cout<<root -> val<<" ";
    inOrderTraversal(root -> right);
}

void changeTree(TreeNode* root) {

    if (!root) return;  // if root null BASE CASE
    int childSum = 0;   // we will be finding child sum for the current node if exist

    if (root -> left)  childSum += root -> left -> val;
    if (root -> right) childSum += root -> right -> val;

    // if child sum < root -> val, we set both children = root -> val
    if (childSum < root -> val) {   

        if (root -> left)  root -> left -> val  = root -> val;
        if (root -> right) root -> right -> val = root -> val;
    }
    // if root-> val < child sum, update root val
    else {
        root -> val = childSum;
    }

    changeTree(root -> left);   // left call
    changeTree(root -> right);  // right call

    // while backtracking we check the child sum again and update root -> val to both child sum
    childSum = 0;
    if (root -> left)  childSum += root -> left -> val;
    if (root -> right) childSum += root -> right -> val;

    if (root -> left || root -> right) root -> val = childSum;
}

int main(){
    
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(13);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(23);
    root->left->right = new TreeNode(14);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    cout<<"BEFORE"<<endl;
    inOrderTraversal(root);
    cout << endl;

    changeTree(root);

    cout<<"AFTER"<<endl;
    inOrderTraversal(root);
    cout << endl;

    return 0;
} 
