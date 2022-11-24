// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        
        // make adj list
        vector<int> adj[n];
        for (auto itr : edges) {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        // queue for bfs, dist array initially all infinity 1e9 here
        queue<int> q;
        vector<int> dist(n, 1e9);

        dist[src] = 0;  // set the source node distance = 0 
        q.push(src);    // push source node in queue for bfs traversal
        
        // bfs
        while (!q.empty()) {

            int node = q.front();   // extract the node
            int d = dist[node];     // store dist till curr node in d
            q.pop();                // pop node

            // iterate in all connected nodes with curr node
            for (auto adjNode : adj[node]) {
                
                // if curr distance is > what we could reach through node
                // then we will update our distance 
                if (dist[adjNode] > d + 1) {
                    
                    dist[adjNode] = d + 1;              // update distance
                    q.push(adjNode);                    // push adjNode in q
                }
            }
        }
        // in dist array we have all distances, update all dist which are still 1e9 to -1, unreachable nodes
        for (auto& itr : dist) if (itr == 1e9) itr = -1;
        return dist;
    }
};
