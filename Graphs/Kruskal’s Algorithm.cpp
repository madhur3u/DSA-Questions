// Kruskal’s Algorithm 
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
class DisjointSet {
    vector<int> size, parent;
public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        } 
    }
    int findParent(int node) {
        if (parent[node] == node) return node;              // if node is the ultimate parent
        return parent[node] = findParent(parent[node]);     // if not we do dfs to find parent, and set curr parent to dfs return, PATH COMPRESSION
    }
    void Union(int u, int v) {

        int pu = findParent(u);         // find ultimate parents of u and v
        int pv = findParent(v);

        if (pu == pv) return;           // if parents already same no need to do UNION

        if (size[pu] > size[pv]) {      // if pu size's bigger it will become parent 
            parent[pv] = pu;
            size[pu] += size[pv];       // size of parent pu -> size of both pu + pv
        }
        else {                          // if pv size's bigger it will become parent
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};    // findParent(int), Union(int, int)
typedef pair<int, int> pii;
class Solution {
	public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        vector<vector<int>> edges;  // make edges vector in format {weight, u, v}
        for (int i = 0; i < V; i++) {
            for (auto& itr : adj[i]) {
                edges.push_back({itr[1], i, itr[0]});
            }
        }
        // from above we will have repititive edges like for 0 1 5 -> {5, 1, 0} & {5, 0, 1}
        // but kruskal algorithm will take care of it as it will take it only once in consideration
        
        // sort the edges in increasing order of weights
        sort(edges.begin(), edges.end());
        
        // now we have all edges with min weights first
        // so we try to form out MST with the min weight first
        int sum = 0;
        DisjointSet ds(V);
        for (auto& edge : edges) {  // iterate in edges
            
            int u = edge[1];        // extract the edge nodes u,v and weight wt
            int v = edge[2];
            int wt = edge[0];
            
            // if the parents of both u and v are same it means u and v are already connected
            // so are alreay part of out MST, so we dont add wt to ans and no need for union
            // when parent not equal, means not yet part of mst
            // union both edges and add weight to sum
            if (ds.findParent(u) != ds.findParent(v)) {
                sum += wt;
                ds.Union(u, v);
            }
        }
        return sum;
    }
};
