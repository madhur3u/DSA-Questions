class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};
    int minimumEffortPath(vector<vector<int>>& h) {
        
        int n = h.size(), m = h[0].size();

        // using dijstra algorithm
        // we will store the min effrt we get till now for a cell in all its bfs iterations
        // make minHeap for dij
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        dist[0][0] = 0;         // starting point 0,0 effort will be zero   
        minHeap.push({0, 0});   // {effort, row * 100 + col}

        // dij traversal bfs
        while (!minHeap.empty()) {

            // extract the row, col and effort from queue top element, pop
            int row = minHeap.top().second / 100;
            int col = minHeap.top().second % 100;
            int effort = minHeap.top().first;
            minHeap.pop();

            // if the curr cell points to destination we return the effort
            // since we store effort, rowcol in pq, it will be sorted acc to min effort
            // so we will be sure that the effort is minimum when we reach last cell 
            if (row == n - 1 && col == m - 1) return effort;

            // traverse in all 4 directions
            for (int i = 0; i < 4; i++) {
                int nr = row + dir[i];      // new row and col index
                int nc = col + dir[i + 1];

                // check validity of new row and new col
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    // calculate the new effort for curr nr, nc
                    // since we are coming from row, col
                    // so effort will be h[row][col] - h[nr][nc], take max with effort as we need max effort of a path
                    int neffort = max(effort, abs(h[row][col] - h[nr][nc]));

                    // check if the new effort we get from prev calc is < prev effort stored in dist
                    // update dist cell and push in queue
                    if (dist[nr][nc] > neffort) {
                        dist[nr][nc] = neffort;
                        minHeap.push({neffort, nr * 100 + nc});
                    }
                }
            }
        }
        return -1;
    }
};
