/*
basic dijkstra algo
we need to find shortest dist from source node till all other nodes
in the end we find max of the dist array
if max == 1e9 means there was a unreachable node so return -1, else return the max element
*/
typedef pair<int, int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // making adj list
        vector<pair<int, int>> adj[n + 1];
        for (auto& itr : times) 
            adj[itr[0]].push_back({itr[1], itr[2]});
        
        // distance vector n + 1 as 1 indexed
        vector<int> dist(n + 1, 1e9);
        priority_queue<pii, vector<pii>, greater<pii> > q; //{curr_dist, node} pq for dij algo
        dist[k] = 0;        // dist of source = 0
        q.push({0, k});     // push 0, source in pq

        // bfs traversal
        while (!q.empty()) {

            int node = q.top().second;      // extract pq top element and pop
            int curr_dist = q.top().first;
            q.pop();

            // iterate in all adj nodes
            for (auto& itr : adj[node]) {

                int adjNode = itr.first;
                int newDist = itr.second;

                // if previous dist we reached adj Node > what we can reach through node
                // so we update dist as we need min dist, also add new pair to pq
                if (dist[adjNode] > curr_dist + newDist) {
                    q.push({curr_dist + newDist, adjNode});
                    dist[adjNode] = curr_dist + newDist;
                }
            }
        }
        // find the max element in dist array
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == 1e9 ? -1 : ans;
    }
};
