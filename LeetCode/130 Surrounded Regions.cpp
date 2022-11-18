//1. Move over the boundary of board, and find O's 
//2. Every time we find an O, perform DFS from it's position
//3. In DFS convert all 'O' to '#'      
//   (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
//4. After all DFSs have been performed, board contains three elements,#,O and X
//5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
//6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'

class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};      // direction array
    int n, m;                           // n and m
    void solve(vector<vector<char>>& a) {
         
        n = a.size(), m = a[0].size();

        // traverse the left and right boundary
        int i = 0;
        while (i < n) {
            if (a[i][0] == 'O') dfs(i, 0, a);
            if (a[i][m - 1] == 'O') dfs(i, m - 1, a);
            i++;
        } 
        // traverse top and bottom boundary
        int j = 0;
        while (j < m) {
            if (a[0][j] == 'O') dfs(0, j, a);
            if (a[n - 1][j] == 'O') dfs(n - 1, j, a);
            j++;
        } 
        // after traversing boundries and marking all Os connected with boundary O using dfs
        // we need to convert all Os still left to X
        // also convert the # to O
        for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            if (a[i][j] == 'O')      a[i][j] = 'X';
            else if (a[i][j] == '#') a[i][j] = 'O';
        }
    }
    // dfs, convert all adjacent Os connected with boundry Os to #
    void dfs(int i, int j, vector<vector<char>>& a) {

        a[i][j] = '#';      // convert O to #

        // traverse in all 4 directions
        for (int k = 0; k < 4; k++) {
            int nr = i + dir[k];        // new coordinates
            int nc = j + dir[k + 1];

            // if the new coordinate is valid and is a O, dfs call again
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && a[nr][nc] == 'O') 
                dfs(nr, nc, a);
        }
    }
};
//We will use boundary DFS to solve this problem
        
      // Let's analyze when an 'O' cannot be flipped,
      // if it has atleast one 'O' in it's adjacent, AND ultimately this chain of adjacent 'O's is 
      // connected to some 'O' which lies on boundary of board
        
      //consider these two cases for clarity :
      /*
        O's won't be flipped          O's will be flipped
        [X O X X X]                   [X X X X X]     
        [X O O O X]                   [X O O O X]
        [X O X X X]                   [X O X X X] 
        [X X X X X]                   [X X X X X]
      
      So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
      
      */
