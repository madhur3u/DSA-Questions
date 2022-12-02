// https://practice.geeksforgeeks.org/problems/number-of-islands/1
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
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &cells) {
        
        int dir[5] = {0,1,0,-1,0};
        
        vector<int> ans;    // this will store no. of islands at each isntant
        vector<vector<int>> vis(n, vector<int>(m, 0));  // visited array 
        DSU ds(n*m);        // make DSU object of n*m
        int islands = 0;    // this will tell us no. of island at each instant
        
        // iterate in cells given to us
        for (auto& itr : cells) {
            
            // extract the row and col
            int r = itr[0], c = itr[1];
            // if we have already visited this cell before than this will not change no. of island
            // as it is already a part of island so push islands and continue to next cell
            if (vis[r][c] == 1) {
                ans.push_back(islands);
                continue;
            }
            // if a new cell, we treat this cell currently as a new island, so islands++
            islands++;
            vis[r][c] = 1;          // also mark cell as visited now
            
            int nodeID = r*m + c;   // nodeID of cell
            
            // iterate in all 4 directions
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i];        // new row and col idx
                int nc = c + dir[i + 1];
                
                // INVALID CASE - if new index out of boundsor cell not visited we cant connect
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc] == 0) continue;
                
                // if we are here means cell represented by nr nc is part of a island
                // so we will try to connect it with node, 1st extract its ID
                int adjNodeID = nr*m + nc;  
                
                // now check if parent of both node and adjNode are diff
                // as if parent same means both are already part of same island so no. of island wont dec
                // if parents diff -> connect nodes and dec count of islands by 1
                if (ds.findParent(nodeID) != ds.findParent(adjNodeID)) {
                    islands--;
                    ds.Union(nodeID, adjNodeID);
                }
            }
            // push no. of islands for curr cell
            ans.push_back(islands);
        }
        return ans;
    }
};
