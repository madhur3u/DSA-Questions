/*
take very zero in bfs q first with distance 0
after that we move one step to all directions from the zeroes stored in queue
for these we store row, col, and dist + 1 in queue if cell is not visited
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();              // n and m
        vector<vector<int>> vis(n, vector<int>(m, 0));      // visited array initially all 0
        vector<vector<int>> ans(n, vector<int>(m, 0));      // ans initially all 0
        queue<vector<int>> q;

        // traverse in matrix and check for all 0s, push row, col, and dist = 0 in queue
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i,j,0});
                    vis[i][j] = 1;
                }
            }
        }
        int dir[] = {0, 1, 0, -1, 0};   // direction array

        // bfs traversal
        while (!q.empty()) {

            // extract the row, col and distance from queue front and pop
            int row = q.front()[0], col = q.front()[1], dist = q.front()[2];
            q.pop();

            // update ans matrix with distance at curr row and col
            ans[row][col] = dist;

            // move 1 step in all direction using dir array
            for (int i = 0; i < 4; i++) {

                // new row and new col coordinates
                int nr = row + dir[i];
                int nc = col + dir[i + 1];

                // if the new row and col are valid and not visited previously
                // push the nr, nc and dist + 1 in queue and mark it as visited
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] == 0) {
                    q.push({nr, nc, dist + 1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};
