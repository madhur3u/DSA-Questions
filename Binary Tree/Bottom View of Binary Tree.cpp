class Solution {
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> bottomView(Node *root) {
        
        vector<int> ans;
        if (!root) return ans; 
        
        map<int, int> mp;           // map {x coord, value at the last x coord we found}
        queue<pair<Node*, int>> q;  // q for dfs with node and x coord
        q.push({root, 0});          // inital node with x coord
        
        // bfs level order traversal
        while (!q.empty()) {
            
            // traverse a level
            int size = q.size();
            while (size--) {
                
                // extract 1st element of level, seprate its node and x coord
                auto it = q.front(); q.pop();
                Node* temp = it.first;
                int x = it.second;
                
                // in level order traversal we traverse from left -> right
                // so if we found a new x ccord we overwrite prev value, it will take care of two x in a same level
                // also in bottom view we need last x coord value in level traversal
                mp[x] = temp -> data;
                
                if (temp -> left) q.push({temp -> left, x - 1});
                if (temp -> right) q.push({temp -> right, x + 1});
            }
        }
        for (auto it : mp) ans.push_back(it.second);    // push bottom view
        return ans;
    }
};
