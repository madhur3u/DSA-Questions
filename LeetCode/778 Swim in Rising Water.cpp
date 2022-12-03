class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap; // minHeap
        vector<vector<bool>> vis(n, vector<bool>(n, 0));    // visited array, can use grid also

        minHeap.push({grid[0][0], 0, 0}); // {maxHeight till now in path, row, col}
        vis[0][0] = 1;                    // mark 1st cell 0,0 as visited

        int dir[5] = {0, 1, 0, -1, 0};    // dir to traverse 4 directions  

        // bfs traversal - dijkstra algo
        // we push height, r, c in queue
        // we go to all 4 directions and in valid paths we compute new geight as max of curr and new height
        // so we have max height in a path as 1st element of heap
        // and we always take the minimum height while pop since minHeap is used
        // so optimal way of using -> from max of all paths that lead to last cell, compute minimum
        while (!minHeap.empty()) {

            int h = minHeap.top()[0];   // extract top el and pop
            int r = minHeap.top()[1];
            int c = minHeap.top()[2];
            minHeap.pop();

            // if we reached last cell return height
            // since we use pq so we will be sure this is the least height we can get to reach end
            if (r == n - 1 && c == n - 1) return h; 

            // iterate in all 4 directions
            for (int i = 0; i < 4; i++) {

                int nr = r + dir[i];        // new row and col index
                int nc = c + dir[i + 1];
                // if index out of bound or cell already visited, continue
                if (nr < 0 || nc < 0 || nr >= n || nc >= n || vis[nr][nc] == 1) continue;

                int nh = max(h, grid[nr][nc]);  // compute new height using max
                minHeap.push({nh, nr, nc});     // push in pq new vector
                vis[nr][nc] = 1;                // mark this new cell visited
            }
        }
        return 0;   // of no use
    }
}; // O(n*n*logn)
