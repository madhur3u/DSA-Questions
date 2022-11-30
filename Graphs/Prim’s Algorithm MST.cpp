// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// https://www.youtube.com/watch?v=mJcZjjKzeqk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=45
// Prim’s Algorithm - GREEDY
typedef pair<int, int> pii;
class Solution {
	public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // min heap to store weights - node pair
        // we use greedy approach take the min weight first and add to spanning tree
        // we add all weights but dur to pq we take tme min weights first so nodes will be visited
        // before we get to the bigger weights, so not included in MST
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        
        // vis array contains all nodes which we have already pushed in MST
        vector<int> vis(V, 0);
        minHeap.push({0, 0}); // {weight, node}, initially push 0 node, dist 0
        
        int sum = 0;    // will hold sum of MST
        
        // bfs traversal
        while (!minHeap.empty()) {
            
            auto it = minHeap.top(); // extract minHeap top and pop
            minHeap.pop();
            
            int node = it.second, wt = it.first;
            
            // if the node is visited, means a better pair of edge is already in MST, continue
            if (vis[node]) continue;
            
            // mark it as visited if not visited
            // also add the weight to sum as we consider this node and weight to be part of MST
            // for {0,0} ,sum wont have any effect
            vis[node] = 1;
            sum = sum + wt;
            
            // iterate in all adj nodes of node
            for (auto& itr : adj[node]) {
                
                int adjNode = itr[0];
                int adjWt = itr[1];
                
                // if the adjNode is not visited, we push {weight, node} in minheap for further process
                if (!vis[adjNode]) minHeap.push({adjWt, adjNode});
            }
        }
        return sum; // totoal sum of MST
    }
};
