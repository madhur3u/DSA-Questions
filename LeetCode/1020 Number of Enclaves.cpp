class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};      // direction array
    int n, m; 
    int numEnclaves(vector<vector<int>>& a) {
        
        n = a.size(), m = a[0].size();

        // traverse the left and right boundary
        int i = 0;
        while (i < n) {
            if (a[i][0] == 1) dfs(i, 0, a);
            if (a[i][m - 1] == 1) dfs(i, m - 1, a);
            i++;
        } 
        // traverse top and bottom boundary
        int j = 0;
        while (j < m) {
            if (a[0][j] == 1) dfs(0, j, a);
            if (a[n - 1][j] == 1) dfs(n - 1, j, a);
            j++;
        } 
        // after traversing boundries and marking all 1s connected with boundary 1 using dfs
        // we need to count all 1s still left 
        // also convert the 2 to 1
        int ans = 0;
        for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            if (a[i][j] == 1)      ans++;
            else if (a[i][j] == 2) a[i][j] = 1;
        }
        return ans;
    }
    void dfs(int i, int j, vector<vector<int>>& a) {

        a[i][j] = 2;      

        // traverse in all 4 directions
        for (int k = 0; k < 4; k++) {
            int nr = i + dir[k];        // new coordinates
            int nc = j + dir[k + 1];

            // if 1 and valid cell dfs call again
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && a[nr][nc] == 1) 
                dfs(nr, nc, a);
        }
    }
};
