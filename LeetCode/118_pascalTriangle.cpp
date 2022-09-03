// https://leetcode.com/problems/pascals-triangle/

// each row is nCr series of a number ranging from 0 to n-1
// so using formula push in ans rows
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        for (int n = 0; n <numRows; n++){
            
            int nCr1 = 1;
            
            vector<int> row;
            row.push_back(nCr1);
            
            for (int r = 1; r <= n; r++){
                
                int nCr = (n - r + 1) * nCr1 / r;
                row.push_back(nCr);
                nCr1 = nCr;
            }
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
};
