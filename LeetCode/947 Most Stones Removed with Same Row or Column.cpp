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
take a grid and stones as coordinates
we have to connect all stones at same row and col -> components
from each component we can remove every stone except one
so we need to find no. of components first
ans = n - stones we wont remove (no. of components)
*/
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        /*
        first we need to create connections, first find out the size of 2d grid we are dealing with
        find max idx of row and col from stones to find row and col size
        */
        int maxr = 0, maxc = 0;
        for (auto& stone : stones) {
            maxr = max(maxr, stone[0]);
            maxc = max(maxc, stone[1]);
        }
        // declare a dsu of size maxr + maxc + 1
        // we map rows from 0 to maxr
        // and cols from (maxr + 1) to maxc -> col = j + (maxr + 1)
        // this way we can easily connect each row and col
        DSU ds(maxr + maxc + 1);
        unordered_set<int> s;   // set stores all rows and cols we have gone through

        for (auto& stone : stones) {

            int r = stone[0];                   // extract row
            int c = stone[1] + (maxr + 1);      // extract col -> give it coord after maxr + 1

            // now we will connect this whole row and whole col
            // so if in future we againfound a coord in same row or col number
            // we can connect them too
            ds.Union(r, c);                     
            s.insert(r);        // push the row and col
            s.insert(c);
        }
        int count = 0;
        // count all nodes who has same parent from the rows and cols stored in set
        for (auto& node : s) {
            if(ds.findParent(node) == node) count++;
        }
        return n - count;   // ans
    }
};
/* O(n*n) time
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        DSU ds(n);

        for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) 
                ds.Union(i, j);
        }
        int count = 0;
        for (int i = 0; i < n; i++) if (ds.findParent(i) == i) count++;

        return n - count;
    }
};
*/
