// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
/*
using set instead of minHeap can dec time minutely
as if we encounter a pair which is taking more distance than in pq we cant delete that and will be iterating through that also
but in set we can delete the prev pair with more distance when we encounter a pair with less dist for same node
*/
class Solution {
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        
        // make set pq
        set<pair<int,int>> set;
        
        // distance initially all infinity
        vector<int> dist(V, 1e9);
        
        // set source distance 0, push in pq
        dist[S] = 0;
        set.insert({0, S}); // pq contains {dist, node} so is sorted acc to distance
        
        // while pq is not empty
        while (!set.empty()) {
            
            // extract distance and curr node from pair and erase the itr from set
            auto itr = *(set.begin());
            int d = itr.first;
            int node = itr.second;
            set.erase(itr);

            // traverse in all connected nodes with node
            for (auto it : adj[node]) {
                
                // extract adjacent node and its weight using adj list
                int adjNode = it[0];
                int wt = it[1];
                
                // now if the dist which was stored earlier for adjNode is greater than the distance
                // which we can get using node then it means current path is shorter than previous
                // so we update the distance and push pair in pq
                if (dist[adjNode] > d + wt) {
                    if (dist[adjNode] != 1e9) set.erase({dist[adjNode], adjNode});
                    dist[adjNode] = d + wt;
                    set.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
