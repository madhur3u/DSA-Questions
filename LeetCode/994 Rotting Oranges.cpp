/*
WATCH VIDEO TO UNDERSTAND BETTER 
The idea is that for each rotten orange, we will find how many fresh oranges there are in its 4 directions. 
If we find any fresh orange we will make it into a rotten orange. One rotten orange can rotten up to 4 fresh oranges present in its 4 directions. 
For this problem,  we will be using the BFS ( Breadth-First Search ) technique.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();

        // queue to store the rotten oranges present at each day at first it store initial rotten oranges
        // after that it will store the rotted oranges in next day and so on  
        queue<pair<int, int>> rotten_oranges;
        int fresh = 0;
        int days = 0;

        // traverse in matrix and find no. of fresh oranges and push initial rotten orange in queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) rotten_oranges.push({i, j});
            }
        }
        // vector for all 4 directions 
        vector<pair<int, int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

        // run the loop till the queue is empty means we cannot rot any more oranges 
        while (!rotten_oranges.empty()) {
            
            // current number of rotted oranges
            // we will pop the rotted oranges and push new rotted oranges so we only pop k times
            // so no new rotted orange is popped
            int k = rotten_oranges.size();

            while (k--) {
                // extract the rotted orange from front and pop
                auto cell = rotten_oranges.front(); 
                rotten_oranges.pop();

                // iterate for all 4 directions
                for (auto dir : directions) {

                    // row and col coordinated using current coordinates and dir vector
                    int row = cell.first + dir.first, col = cell.second + dir.second;

                    // if row , col out of matrix or the block dont have a fresh orange continue for next iteration
                    if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] != 1)
                        continue;
                    
                    // else rot the current fresh orange, push its coordinate in queue
                    // dec no. of fresh oranges by 1
                    grid[row][col] = 2;
                    rotten_oranges.push({row, col});
                    fresh--;
                }
            }
            // increase day only when we were able to rot any fresh orange, for that queue will not be empty
            if (!rotten_oranges.empty()) days++;
        }
        // if any fresh orange remain after above computation means we cannot rot that so return - 1
        // else return no. of days
        return (fresh) ? -1 : days;
    }
};
