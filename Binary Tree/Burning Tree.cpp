// https://practice.geeksforgeeks.org/problems/burning-tree/1

// make child -> parent map and find the address of the target node in target
// in dfs fn send the target node and calculate no. of steps we need till all nodes are visited
// keep visited nodes in a set

class Solution {
    public:
    unordered_map<Node*, Node*> parent;     // child -> parent map
    unordered_set<Node*> visited;           // set for visited or burnt nodes
    Node* target;                           // address of node we burn first
    
    //make child -> parent map
    void makeParentMap(Node* root, int t) {

        if (!root) return;
        if (root -> data == t) target = root;   // find target address where val == t
        if (root -> left) {
            parent[root -> left] = root;
            makeParentMap(root -> left, t);
        }
        if (root -> right) {
            parent[root -> right] = root;
            makeParentMap(root -> right, t);
        }
    }
    int dfs (Node* node) {
        
        if (!node) return 0;                                // BASE CASE
        if (visited.find(node) != visited.end()) return 0;  // invalid case, node already burnt/visited
        visited.insert(node);                               // insert node in visited 
        
        // 1 is the time needed to burn current node
        // we make all 3 calls and add max time from all of them
        return 1 + max({dfs(node -> left), dfs(node -> right), dfs(parent[node])});
    }
    int minTime(Node* root, int t) {
        
        if (!root) return 0;        // map doesnt exist
        makeParentMap(root, t);     // make child -> parent map and find target node address
        return dfs(target) - 1;     // find and from dfs, -1 as we burn target node in 0th time
    }
};
