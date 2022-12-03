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
    int getSize(int node) {return size[node];}  // adiition for this q
};  
// DSU CLASS ENDS
/*
Iterate over rows and columns in the matrix, if a cell matrix[r][c] == 1 then we connect that 
cell with its landing neighboring cells by using Union-Find.
Iterate over rows and columns in the matrix again, this time we calculate the new size that can 
be formed if we turn matrix[r][c] from 0 into 1, that is:

    If matrix[r][c] == 0 then:
        Get unique parent ids of landing neighboring cells to calculate component size. 
        (We get unique parent ids to avoid calculating the size of 2 connected component two times)
        
        Calculate total size can be formed.
        Update the largest size can be formed so far to our answer.
*/
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int dir[5] = {0, 1, 0, -1, 0};                     
        int n = grid.size();    
        DSU ds(n * n); 
        int oneCount = 0;     

        // STEP 1 : Connecting all islands initially present
        // LC 200 -> give unique idto each cell -> row*n + col
        for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {

            int nodeID = (i * n) + j;   // extract curr node id

            if (grid[i][j] == 1) {      // if curr cell has 1
                oneCount++;             
                for (int k = 0; k < 2; k++) {   // right and down only -> as we iterate row wise

                    int nr = i + dir[k];        // new row and col index
                    int nc = j + dir[k + 1];

                    if (nr < n && nc < n && grid[nr][nc] == 1) {    // checking validity

                        int adjNodeID = (nr * n) + nc;  // adj node id
                        ds.Union(nodeID, adjNodeID);    // connect both
                    }
                }
            }
        }
        // STEP 1.1 -> special case : when all are 1 in grid
        // if all are one that will be the max island we cannot inc its size so return n*n
        if (oneCount == n*n) return oneCount; 

        // STEP 2 : CREATING MAX ISLAND
        // we will iterate each 0 -> checkall 4 directions and find islands size
        // maximise the size
        int maxIsland = 0;
        for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {

            unordered_set<int> islands;         // store uniwue island for each zero

            if (grid[i][j] == 0) {              // only 0 will be considered
                for (int k = 0; k < 4; k++) {   // all 4 directions

                    int nr = i + dir[k];        // new row and col index
                    int nc = j + dir[k + 1];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1) {  // check validity

                        // extract id, insert that parent of island we found in set
                        // using this we can prevent from taking one island > 1 time
                        int adjNodeID = (nr * n) + nc;              
                        islands.insert(ds.findParent(adjNodeID));   
                    }
                }
            }
            // temp -> store size of island is curr 0 will be mad 1
            // iterate in setand add size of islands in temp
            int temp = 0;
            for (auto& itr : islands) {
                temp += ds.getSize(itr);
            }
            maxIsland = max(maxIsland, 1 + temp);   // maximise the ans, +1 for the 0 cell
        }
        return maxIsland;
    }
};
