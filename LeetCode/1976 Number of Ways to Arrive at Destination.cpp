// https://www.youtube.com/watch?v=_-0mx0SmYxA&t=1131s
// PLEASE SEE VIDEO
// same as normal dijkstra but we also add dp element
// ways array store no. of paths we can reach the node at shortest distance

// shortcuts
typedef long long ll;
typedef pair<ll, ll> pii;
ll MOD = 1000000007;
ll INF = LONG_MAX;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // making graph - undirected
        vector<pii> adj[n];
        for (auto& itr : roads) {
            adj[itr[0]].push_back({itr[1], itr[2]});
            adj[itr[1]].push_back({itr[0], itr[2]});
        }
        
        vector<ll> dist(n, INF);    // for dijkstra
        vector<ll> ways(n, 0);      // dp array ways store no. of ways to reach node in shortest dist

        priority_queue<pii, vector<pii>, greater<pii>> q; //{curr_dist, node} pq for dij algo
        dist[0] = 0;        // dist of source = 0
        ways[0] = 1;        // no. of ways to reach source will be 1
        q.push({0, 0});     // push {0, source} in pq

        // bfs traversal
        while (!q.empty()) {

            ll node = q.top().second;       // extract pq top element and pop
            ll curr_dist = q.top().first;
            q.pop();

            // this will happen when we have already found a shortest distance
            // but pq has also stored some greater distance, so we dont want to iterate unnecessarily
            if (curr_dist > dist[node]) continue;

            // iterate in all adj nodes
            for (auto& itr : adj[node]) {

                ll adjNode = itr.first;     // extract new node and its distance
                ll newDist = itr.second;

                // if the new distance we can reach using node == what already stored
                // means we have found more way(s) to reach shortest distance
                // add ways of both what already stored till now and ways we will get using curr adjNode
                if (dist[adjNode] == curr_dist + newDist) 
                    ways[adjNode] = (ways[node] + ways[adjNode]) % MOD;
                
                // normal dij if statement
                else if (dist[adjNode] > curr_dist + newDist) {
                    dist[adjNode] = curr_dist + newDist;        // update distance
                    ways[adjNode] = ways[node] % MOD;           // no. of ways will be what we can reach through node     
                    q.push({curr_dist + newDist, adjNode});     // push pair in pq
                }
            }
        }
        return ways[n - 1];     // ways to reach n - 1 th node
    }
};
