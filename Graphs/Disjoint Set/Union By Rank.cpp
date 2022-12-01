#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        } 
    }
    int findParent(int node) {
        if (parent[node] == node) return node;              // if node is the ultimate parent
        return parent[node] = findParent(parent[node]);     // if not we do dfs to find parent, and set curr parent to dfs return, PATH COMPRESSION
    }
    void unionByRank(int u, int v) {

        int pu = findParent(u);         // find ultimate parents of u and v
        int pv = findParent(v);

        if (pu == pv) return;           // if parents already same no need to do UNION

        if (rank[pu] > rank[pv]) {      // if pu rank's bigger it will become parent 
            parent[pv] = pu;
        }
        else if (rank[pu] < rank[pv]) { // if pv rank's bigger it will become parent
            parent[pu] = pv;
        }
        else {                          // in case of equal rank, we can make anyone as parent
            parent[pu] = pv;            // choosing pv to be parent here
            rank[pv]++;                 // also inc the rank of parent
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2); 
    ds.unionByRank(2, 3); 
    ds.unionByRank(4, 5); 
    ds.unionByRank(6, 7); 
    ds.unionByRank(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionByRank(3, 7); 

    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
}
