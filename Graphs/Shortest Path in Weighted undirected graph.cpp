// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        // make adj list using the edges given also place the weights in 2nd of pair
        vector<pair<int,int>> adj[n + 1];
        for (auto itr : edges) {
            adj[itr[0]].push_back({itr[1], itr[2]});
            adj[itr[1]].push_back({itr[0], itr[2]});
        }
        // we use Djisktra algo to find the shortest path with some tweaking
        // when we are reaching a node with min distance we also need to know from which node we have reached here
        // so we need to note the parent from which we are reaching with min distance
        // ElogV
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n + 1, 1e9);
        
        // for parent we make a parent array with indices denoting the node and values the parent
        // initially place the nodes in value parent[i] = i
        // so for our source i.e. 1 its parent will be 1 (this will be use to terminate ans loop)
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;

        // source is always 1st node so its distance will be 0
        // update and push in pq
        dist[1] = 0;
        pq.push({0, 1}); // pq contains {dist, node} so is sorted acc to distance
        
        // bfs
        while (!pq.empty()) {
            
            int d = pq.top().first;     // extract curr node and its distance, pop
            int node = pq.top().second;
            pq.pop();

            // iterate in all connected nodes with curr node
            for (auto it : adj[node]) {
                
                int adjNode = it.first;     // adj Node and its weight
                int wt = it.second;
                
                // if curr distance is > what we could reach through node
                // then we will update our distance 
                if (dist[adjNode] > d + wt) {
                    
                    dist[adjNode] = d + wt;             // update distance
                    parent[adjNode] = node;             // also now parent of adjNode is node, update it
                    pq.push({dist[adjNode], adjNode});  // push this dist, node pair in queue
                }
            }
        }
        // if distance at end node is stll 1e9 means we were unale to reach that node
        
        if (dist[n] == 1e9) return {-1};    
        
        // logN
        // now we need to create ans, we create that from end node
        vector<int> ans;
        int node = n;       // store end node in node
        
        // itertate till node and its parents are equal
        while (node != parent[node]) {
            
            // push curr node in ans
            ans.push_back(node);
            node = parent[node];    // since we have stored parent in array, so now node will be its parent, this will go on till we reach 1
        }
        // push 1 as it wont be pushed in loop
        ans.push_back(1);
        
        // our ans will be in reverse so reverse it and return
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
