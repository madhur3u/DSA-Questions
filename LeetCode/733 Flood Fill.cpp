/*
BFS APPROACH
we first push the selected cell in queue {sr, sc}
then change color of this cell to newColor given
and store old color in a a variable
we need to change all adjacent cells with old color
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if (image[sr][sc] == color) return image;   // if color change not needed
        
        int n = image.size(), m = image[0].size();  

        // make queue for bfs and push the cell given to us
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<pair<int, int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};    // dir vector

        // store old color and change current cell color to new color
        int oldcolor = image[sr][sc];
        image[sr][sc] = color;

        // bfs traversal
        while (!q.empty()) {

            auto cell = q.front(); q.pop();     // pop the current cell 

            // traverse in all directions 
            for (auto dir : directions) {

                // make new row and col, add dir variable to curr cell elements for that
                int row = cell.first + dir.first, col = cell.second + dir.second;

                // invalid case
                // out of index 
                // image[row][col] != oldcolor -> cell color wont be changed as it is not of oldcolor
                if (row < 0 || col < 0 || row >= n || col >= m || image[row][col] != oldcolor)
                    continue;
                
                // if we are here means we have adjacent cell of old color
                // change the color to new
                // push this cell in q
                image[row][col] = color;
                q.push({row, col});
            }
        }
        return image;
    }
};
