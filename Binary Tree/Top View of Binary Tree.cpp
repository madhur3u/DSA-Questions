// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// https://takeuforward.org/data-structure/top-view-of-a-binary-tree/

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        
        vector<int> ans;
        if (!root) return ans; 
        
        // map will have x coordinate and the 1st element we found at that x coordinate
        map<int, int> mp;
        // store x coordinate ind node in queue
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        // bfs traversal, we go level by level so that we get 1st element for particular x coordinate
        while (!q.empty()) {
            
            // extract front node, extract the node and x coordinate
            auto it = q.front(); q.pop();
            Node* temp = it.first;
            int x = it.second;
            
            // if we get thsi x coord 1st time push the data in map
            if (mp.find(x) == mp.end()) mp[x] = temp -> data;
            
            // push nodes if exist
            if (temp -> left) q.push({temp -> left, x - 1});
            if (temp -> right) q.push({temp -> right, x + 1});
        }
        
        for (auto it : mp) ans.push_back(it.second);    // insert top view in ans
        return ans;
    }

};
