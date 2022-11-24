/*
Use BFS approach to find shortest path like we solve for graph problems. 
You can think of adjacent cells with value = 0 having an undirected edge between them.
Apply BFS and update counter at everly level.
To track levels I have used size. It is equal to number of nodes in current level.
If you are able to reach (n-1, n-1) return its level otherwise return -1.
Little Optimization : Rather than keeping visited vector, after we have pushed a node in the queue make its value in grid equal to 1. 
This would make it unavailable to process next time we encounter it. However this method will corrupt the memory DONT USE WHEN WE CANT MODIFY INPUT.
*/
class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0},{-1,1},{1,1},{1,-1},{-1,-1}};    // direction vector 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        // if the 1st or last cell is 1 means no path possible
        if (grid[0][0] == 1 || grid[n -1][n - 1] == 1) return -1;

        queue<pair<int, int>> q;    // q for bfs
        q.push({0,0});              // push the source cell in q 0,0
        grid[0][0] = 1;             // mark source cell as visited, here we are mdifying grid to 1

        int dist = 0;               // initial distance

        while (!q.empty()) {

            int size = q.size();    // we traverse level wise to get distance so take size
            dist++;                 // inc dist as first 0 also has to be considered

            // traverse aall cells in curr level
            while (size--) {

                // extract the row, col from queue front and pop
                int row = q.front().first, col = q.front().second; q.pop();

                // if we reached destination return distance
                if (row == n - 1 && col == n - 1) return dist;

                // move 1 step in all directions using dir array
                for (int i = 0; i < 8; i++) {

                    // new row and new col coordinates
                    int nr = row + dir[i].first;
                    int nc = col + dir[i].second;

                    // if the new row and col are valid and not visited previously
                    // push the nr, nc in queue and mark it as visited
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0) {
                        q.push({nr, nc});
                        grid[nr][nc] = 1;
                    }
                }
            }
        } 
        return -1;  // if we never found path, return -1
    }
};
