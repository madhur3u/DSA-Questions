// https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
// Print adjacency list

class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {

        vector<vector<int>> ans(V);
        
        // i from 0 to n - 1 will represent the nodes 
        for (int i = 0; i < V; i++) {
            
            // push the node at ith pos
            ans[i].push_back(i);
            
            // now for the node we need to push all other connected nodes in ans at ith pos vector
            // for that we traverse in adj[i], adj[i] will have the vector of all connected node with i
            // push all elements from adj[i] vector in ans[i] vector
            for (int j : adj[i]) {
                ans[i].push_back(j);
            }
        }
        return ans;
    }
};
