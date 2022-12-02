// DSU CLASS STARTS
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
This can be easily solved usin multisource dfs or BFS but we used DSU here
we give each cell in matrix a nodeID we can have nodes from 0 to (n*m) - 1
and nodeId = (rowIdx * m) + colIdx;
we will use the Ids to connect graph and make ans
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int dir[3] = {0, 1, 0};                     // 2 directions right and dowm
        int n = grid.size(), m = grid[0].size();    // n and m
        int zeroes = 0;                             // no. of zero we encounter in grid

        // declare object of size n*m, our parent array will have all nodes 0 to n*m
        DSU ds(n * m);      

        // iterate in grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int nodeID = (i * m) + j;   // extract curr node id

                // if the node is 1 means can be part of island so we will do our operations
                // we will move right and down and connect nodes if they are also 1, making island
                // we dont go up and left as we are iterating row wise so no need for that
                if (grid[i][j] == '1') {
                    for (int k = 0; k < 2; k++) {

                        int nr = i + dir[k];        // new row and col index
                        int nc = j + dir[k + 1];

                        // checking validity of the cell, if it exist in grid and is '1'
                        if (nr < n && nc < m && grid[nr][nc] == '1') {

                            int adjNodeID = (nr * m) + nc;  // extract adj node ID
                            ds.Union(nodeID, adjNodeID);    // union node and adj node to form island
                        }
                    }
                }
                else zeroes++;  // counter of zeroes in grid
            }
        }
        int ans = 0;    // ans to hold no. of islands
        for (int i = 0; i < n * m; i++) {
            if (ds.findParent(i) == i) ans++;  // count islands, i is its own parent
        }
        // island case
        // i == parent will be in two case
        // 1. when cell was never visited means cell == 0 case, as it was never modified in parent array
        // 2. when its part of island and ultimate parent of a component
        // so and will be all islands - zeroes
        return ans - zeroes;
    }
};
