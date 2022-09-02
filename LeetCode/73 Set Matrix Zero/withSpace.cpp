// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        
        int n = a.size();
        int m = a[0].size();
        
        // in this we make 2 sets for row and col
        //and push index of those row and col to sets
        // in which we encounter a zero
        // so at the end we will have all rows and cols index which we have to make zero
        unordered_set<int> rows;
        unordered_set<int> cols;
        
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if (a[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        // making row zeroes
        for (auto row : rows){
            for (int j = 0; j<m; j++){
                a[row][j] = 0;
            }
        }
        
        // making col zeroes
        for (auto col : cols){
            for (int i = 0; i<n; i++){
                a[i][col] = 0;
            }
        }
    }
};

// O(n+m) space
// O(n*m) time
