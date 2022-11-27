// Dijstra algo with stops as the 1st element in q
// since stops are inc by 1 always so no need to use pq

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // make adj list from the given flights data, also add dist in pair for a flight 
        vector<pair<int, int>> adj[n];
        for (auto& itr : flights) {
            adj[itr[0]].push_back({itr[1], itr[2]});
        }
        
        queue<vector<int>> q;       // q for dij bfs
        q.push({0,src,0});          // {stops, node, distance}
        vector<int> dist(n, 1e9);   // dist array with all elements inf first
        dist[src] = 0;              // set source distance zero

        // bfs traversal
        while (!q.empty()) {

            // extract all from the curr node stored in q front and pop
            int stop = q.front()[0];
            int node = q.front()[1];
            int curr_dist = q.front()[2]; q.pop();

            // if the stop > k, since we have to complete journey in atmost k stops
            // so we dont want stop to be > k, when stop = k + 1, we can have our ans
            // also since q has stop as first element and we are inc it by 1 only
            // so if stop is k + 1 now all other q elements will have stop > k also
            if (stop > k) break;

            // iterate in all connected nodes
            for (auto& itr : adj[node]) {
                
                // extract adj Node and its distance from itr
                int adjNode = itr.first;
                int new_dist = itr.second;

                // if the curr dist stored in array > what we can reach from node
                // then we update distance and also push in q
                if (dist[adjNode] > curr_dist + new_dist) {
                    dist[adjNode] = curr_dist + new_dist;
                    q.push({stop + 1, adjNode, curr_dist + new_dist});
                }
            }
        }
        // when we are out of loop we check the distance array for distance of destination
        // if dist == inf, means we never reached there with k stops so return -1
        // else return whatever distance is stored
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
