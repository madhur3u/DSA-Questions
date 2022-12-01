#include <bits/stdc++.h>
using namespace std;

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
    void unionBysize(int u, int v) {

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
};
int main() {
    DisjointSet ds(7);
    ds.unionBysize(1, 2); 
    ds.unionBysize(2, 3); 
    ds.unionBysize(4, 5); 
    ds.unionBysize(6, 7); 
    ds.unionBysize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionBysize(3, 7); 

    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	  return 0;
}
