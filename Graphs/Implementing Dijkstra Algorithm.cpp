// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
class Solution {
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        
        // make minheap of pairs where we store {dist, node}
        // can be done using q but time will increase
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // distance initially all infinity
        vector<int> dist(V, 1e9);
        
        // set source distance 0, push in pq
        dist[S] = 0;
        pq.push({0, S}); // pq contains {dist, node} so is sorted acc to distance
        
        // while pq is not empty
        while (!pq.empty()) {
            
            // extract distance and curr node from pair and pop the pair from pq
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // traverse in all connected nodes with node
            for (auto it : adj[node]) {
                
                // extract adjacent node and its weight using adj list
                int adjNode = it[0];
                int wt = it[1];
                
                // now if the dist which was stored earlier for adjNode is greater than the distance
                // which we can get using node then it means current path is shorter than previous
                // so we update the distance and push pair in pq
                if (dist[adjNode] > d + wt) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
