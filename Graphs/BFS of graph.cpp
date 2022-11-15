// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {

        vector<int> bfs;            // vector holds ans
        queue<int> q;               // queue for bfs
        int visited[V] = {0};       // visited array to not take those nodes again
        
        q.push(0);                  // initially push 0th node in queue
        visited[0] = 1;             // mark 0 visited
        
        // bfs traversal
        while (!q.empty()) {
            
            int node = q.front(); q.pop();  // extract node and pop
            bfs.push_back(node);            // push node in and
            
            for (int it : adj[node]) {      // now in adjancency list traverse in all connected nodes for current node
                if (!visited[it]) {         // if it is not visited
                    visited[it] = 1;        // mark as visited
                    q.push(it);             // push in q
                }
            }
        }
        return bfs;
    }
};
