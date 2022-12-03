// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
// DSU CLASS STARTS
class DSU {
    public:
    vector<int> size, parent;
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        } 
    }
    int findParent(int node) {
        if (parent[node] == node) return node;              
        return parent[node] = findParent(parent[node]);     
    }
    void Union(int u, int v) {  // by size

        int pu = findParent(u);       
        int pv = findParent(v);

        if (pu == pv) return;           

        if (size[pu] > size[pv]) {     
            parent[pv] = pu;
            size[pu] += size[pv];     
        }
        else {                        
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};  
// DSU CLASS ENDS
/*
STEP 1 : Count the number of components without the edge
STEP 2 : Insert the edge in DSU
STEP 3 : Count the number of components with the edge

if both the count are same then that edge was not a bridge otherwise it was a bridge
*/
class Solution {
	public:
    int isBridge(int V, vector<int> adj[], int c, int d) {
        
        // implementing it using DSU
        DSU ds(V);
        // STEP 1
        for (int u = 0; u < V; u++) {
            for (auto& v : adj[u]) {
                if ((u == c && v == d) || (u == d && v == c)) continue; // excluding the edge {c, d}
                ds.Union(u, v); // do union of all ther edges
            }
        }
        // count the no. of components without the edge {c, d}
        int count1 = 0; // no. of components without edge c, d
        for (int i = 0; i < V; i++){
            if (ds.findParent(i) == i) {
                count1++;
            }
        } 
        // STEP 2 : insert the edge
        ds.Union(c, d);
        
        // STEP 3
        int count2 = 0; // no. of components with edge c, d
        for (int i = 0; i < V; i++){
            if (ds.findParent(i) == i) {
                count2++;  
            }
        } 
        return count1 != count2;
    }
};
