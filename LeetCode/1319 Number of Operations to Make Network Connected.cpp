class DSU {
    vector<int> size, parent;
    public:
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
    void Union(int u, int v) {  // union by size

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
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& a) {

        // We need at least n - 1 cables to connect all nodes (like a tree / MST).
        // If connections.size() < n - 1, we can directly return -1
        if (a.size() < n - 1) return -1;
        /*
        If we have enough cables i.e. >= n - 1, we don't need to worry about where we can get the cable from.
        We only need to count the number of connected networks(provinces / islands / components in graph).
        To connect two unconneccted networks, we need to set one cable.
        The number of operations we need = the number of connected networks(components) - 1 
        */
        // for finding out components we can use union-find or DFS
        // make obj ds of dsu
        // make disjoint set using the edges given to us
        DSU ds(n);
        for (auto& itr : a) {
            ds.Union(itr[0], itr[1]);
        }

        // comp -> no. of components / connected networks
        int comp = 0;

        // for diff componets we will have that number of ultimate parents
        // so count ultimate parents
        for (int i = 0; i < n; i++) {
            if (ds.findParent(i) == i) comp++;
        }
        return comp - 1;    // no. of cables needed
    }
};
