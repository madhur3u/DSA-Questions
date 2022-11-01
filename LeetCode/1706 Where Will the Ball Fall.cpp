// O(N*M)
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m);

        // traverse in all columns, as we fall a ball in each col
        for (int c = 0; c < m; c++) {

            // current col and row pointer
            int col = c, row;
            // traverse in rows
            for (row = 0; row < n; row++) {

                // if we have 1, we check if to its right we also have 1 then bal wont get stuck
                // if this is the last column (col + 1 < m) means ball will get stuck to wall
                // so checking that case also
                if (grid[row][col] == 1 && col + 1 < m && grid[row][col + 1] == 1) 
                    col++;

                // same for when we have -1, we check left row, also check if wall exist on left
                else if (grid[row][col] == -1 && col - 1 >= 0 && grid[row][col - 1] == -1)
                    col--;

                // if we are at else means ball stuck so break
                else 
                    break;
            }
            // if row has reached out of index means ball was able to get out push col, else push -1
            ans[c] = (row == n) ? col : -1;
        }
        return ans;
    }
};
