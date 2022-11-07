// https://practice.geeksforgeeks.org/problems/children-sum-parent/1

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        
        // if root is null or a leaf node
        if (!root || (!root-> left && !root -> right)) return 1;
        
        // sum to hold sum of children
        int sum = 0;
        if (root -> left)  sum += root -> left  -> data;
        if (root -> right) sum += root -> right -> data;
        
        // compares root data with sum, and call left and right, & all results
        return (root -> data == sum) & isSumProperty(root -> left) & isSumProperty(root -> right);
    }
};
