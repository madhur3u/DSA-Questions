class Solution{
    public:
    vector<string> res;
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string path = "";
        DFS (m, 0, 0, path);
        return res;
    }
    
    void DFS(vector<vector<int>> & maze, int i, int j, string path){
        
        // if we are at destination and element = 1 means path found
        if (i == j && j == maze.size() - 1 && maze[i][j] == 1){
            res.emplace_back(path);
            return;
        }
        
        // BASE CASE AND WRONG CASE 
        if (i < 0 || j < 0 || i >= maze.size() || j >= maze[0].size() || maze[i][j] == 0)
            return;
        
        // change the current element at i, j so we do not return back to it in other fn calls
        maze[i][j] = 0;
            
        DFS(maze, i + 1, j, path + 'D');  // down
        DFS(maze, i, j + 1, path + 'R');  // right
        DFS(maze, i - 1, j, path + 'U');  // up
        DFS(maze, i, j - 1, path + 'L');  // left
        
        // change back the current element to original
        maze[i][j] = 1;
    }
};
