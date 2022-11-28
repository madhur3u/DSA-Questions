// https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// https://www.youtube.com/watch?v=0vVofAhAYjc&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=42
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        // relaxing the edges N - 1 (V-1) times
        // we iterate V - 1 times as edges might be inc in dec order in worst case
        // and for that we need V-1 iterations
        for (int i = 0; i < V - 1; i++) {
            for (auto& itr : edges) {
                
                int u = itr[0];         // eextract u -> v and edge weight
                int v = itr[1];
                int weight = itr[2];
                
                // if this dist has been reached earlier means not INF
                // and we can reach v node in lesser distance than already stored
                // then we update dist array
                if (dist[u] != 1e8 && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        // CHECKING FR NEGETIVE CYCLE : Nth ITERATION
        // we are sure that our dist array will complete in N - 1 iterations
        // if there is any change in dist array in Nth iteration means graph has a negetive cycle
        for (auto& itr : edges) {
                
            int u = itr[0]; 
            int v = itr[1];
            int weight = itr[2];
                
            // same condition but this indicates negetive cycle at Nth iteration
            if (dist[u] != 1e8 && dist[v] > dist[u] + weight) {
                return {-1};
            }
        }
        return dist;
    }
};
/*
Time Complexity:  O(V * E), where V is the number of vertices in the graph and E is the number of edges in the graph
Auxiliary Space: O(E)
*/
