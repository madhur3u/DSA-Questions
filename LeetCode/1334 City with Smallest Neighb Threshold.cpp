class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        
        // make adj grid with relation representing weights
        vector<vector<int>> grid(n, vector<int>(n, 1e9));
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            grid[u][v] = wt;
            grid[v][u] = wt;
        }
        // set the same dist from node <-> node = 0
        for (int i = 0; i < n; i++) grid[i][i] = 0;

        // Floyd Warshal Algorithm 
        // make grid, all of grid elements after this will have shortest distance
        for (int k = 0; k < n; k++)  
        for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);

        // ans will hold the City With the Smallest Number of Neighbors at a Threshold Distance
        // countMax -> no. of cities withon thrs, we need to minimise countMax
        int ans = 0, countMax = n + 1;
        for (int i = 0; i < n; i++) {

            // compute the currCount -> no. of cities within thrs from ith node 
            int currCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && grid[i][j] <= k) currCount++;
            }
            // minimise countMax
            if (currCount <= countMax) {
                countMax = currCount;
                ans = i;                // ans update if lesser connected cities found
            }
        }
        return ans;
    }
};


/*  2ND SOLUTION USING DIJKSTRA
First, we need to make the adjacency list for the graph which contains for each city the city to which 
it is connected, and the edge weight of that edge.
Now, we have to run Dijkstra’s algorithm for each city to find the distance of all other cities to it.
Make dist array for each city (a 2d array can also be used to store each relation but will use more space)

initially set countMax to > n
ans count no. of cities we can reach within k dist
minimise the answer
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        
        // STEP 1 : make adj list from edges
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        // ans will hold the City With the Smallest Number of Neighbors at a Threshold Distance
        // countMax -> no. of cities withon thrs, we need to minimise countMax
        int ans = 0, countMax = n + 1;
        for (int i = 0; i < n; i++) {

            // make dist array with all inf first
            // call dij algorithm to make dist array -> min dist from ith node to all other nodes
            vector<int> dist(n, 1e9);
            dijkstra(n, adj, i, dist);  // (nodes, adjList, curr Node, dist array)

            // compute the currCount -> no. of cities within thrs from ith node 
            int currCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[j] <= k) currCount++;
            }
            // minimise countMax
            if (currCount <= countMax) {
                countMax = currCount;
                ans = i;                // ans update if lesser connected cities found
            }
        }
        return ans;
    }
    // SIMPLE DIJKSTRA FUNCTION : make array from source to all nodes of shortest distance
    void dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S, vector<int>& dist) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[S] = 0;
        pq.push({0, S}); 
        
        while (!pq.empty()) {
            
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                
                int adjNode = it.first;
                int wt = it.second;

                if (dist[adjNode] > d + wt) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }
};
