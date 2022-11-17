// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    
    // make a visited array
    // loop from all nodes 0 to v - 1, if not visited
    bool isCycle(int V, vector<int> adj[]) {

        int visited[V] = {0};
        for (int i = 0; i < V; i++) {
            if (!visited[i]) 
                if (cycledetection(i, adj, visited)) return true;
        }
        return false;
    }
    // in this we will do bfs traversal
    // we will tryto traverse nodes
    // if we found a node which was already visited 
    // check if it is parent, if not parent the means that node was visited by someone else too before
    // and now our current node is visiting that too, it means we have found a cycle
    bool cycledetection(int i, vector<int> adj[], int vis[]) {
        
        vis[i] = 1;                     // mark curr node visited
        queue<pair<int, int>> q;        // q for bfs
        q.push({i, -1});                // push node, parent pair in bfs, -1 as current i dont have a parent
        
        // bfs traversal
        while (!q.empty()) {
            
            int node = q.front().first;     // extract node
            int parent = q.front().second;  // extract parent
            q.pop();                        // pop front
            
            // iterate in adj list all connected nodes of curr node
            for (auto adj_node : adj[node]) {
                
                // if node is not visited then mark it as visited and push in q
                if (!vis[adj_node]) {
                    vis[adj_node] = 1;
                    q.push({adj_node, node});
                }
                // if node was visited before, and isnot the parent of node
                // it means it was visited by someone before, so cycle detected
                // return true
                else if (adj_node != parent) {
                    return true;
                }
            }
        }
        return false;   // never found a cycle
    }
};
