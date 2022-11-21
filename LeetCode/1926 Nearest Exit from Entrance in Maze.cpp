// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/solutions/2640032/nearest-exit-from-entrance-in-maze/
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        
        int n = maze.size(), m = maze[0].size();    // n and m
        int steps = 1;                              // steps can never be zero, taking initial as 1

        queue<pair<int, int>> q;        // q for bfs stores cell
        q.push({e[0], e[1]});           // put entrance coordinates in q
        maze[e[0]][e[1]] = '+';         // mark entrance visited, marking it same as wall char

        int dir[] = {0, 1, 0, -1, 0};   // direction array

        // bfs traversal
        while (!q.empty()) {
            
            int size = q.size();    // we traverse level be level so extract current size

            // iterate till all cells of current level are traversed
            while (size--) {

                auto [r, c] = q.front();    // extract curr row ans col coordinates
                q.pop();                    // pop from queue

                // iterate in all 4 diections from r, c
                for (int i = 0; i < 4; i++) {

                    int nr = r + dir[i];        // new row and col coordinates
                    int nc = c + dir[i + 1];

                    // check if the nr nc are valid, it should be within maze and a empty cel == '.'
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m && maze[nr][nc] == '.') {
                        
                        // if its valid && a cell in corner means exit found, return steps
                        if (nr == 0 || nc == 0 || nr == n - 1 || nc == m - 1) return steps;

                        q.push({nr, nc});       // else push curr coord in q
                        maze[nr][nc] = '+';     // mark cell as visited
                    }
                }
            }
            steps++;    // inc steps when a level is traversed
        }
        return -1;      // if ans never found
    }
};
/*
Algorithm

    Initialize an empty queue q to store all the nodes to be visited.
    
    Add entrance to queue and mark entrance as visited.
    
    While we don't reach an exit and queue still has cells, pop the first cell from queue. 

    We check its neighboring cells in all four directions, if it has an unvisited neighbor cell:
        If this neighbor cell is an exit, return its distance from the starting position, steps.
        Otherwise, we mark it as visited, and add it to queue.
    
    If we finish the iteration and no exit is found, return -1.
*/
