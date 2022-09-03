// https://leetcode.com/problems/spiral-matrix/
// -> -> -> ...

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        
        int n = a.size();
        int m = a[0].size();
        
        // variables that will control the border
        // initially set them at their min and max position
        int rmin = 0;
        int cmin = 0;
        int rmax = n - 1;
        int cmax = m - 1;
        
        // tr will tell us how many no.s has been pushed to ans vector
        // it should be n*m 
        int tr = 0;
        vector<int> ans;
        
        // tr < n*m so if all no.s are pushed no need to loop more
        while (tr < n*m){
            
            // 1st row only j will inc till cmax
            for (int i = rmin, j = cmin; j <= cmax && tr < n*m; j++){
                ans.push_back(a[i][j]);
                tr++;
            }
            // after whole first row is pushed to ans
            // we do not need to traverse in 1st row again
            // so in rmin, so top border shift downs
            rmin++;
            
            // this print the last column
            for (int i = rmin, j = cmax; i <= rmax && tr < n*m; i++){
                ans.push_back(a[i][j]);
                tr++;
            }
            // cmax--, so that we do not traverse this col again
            // it will shift the cmax border leftwards
            cmax--;
            
            // traverse last row, in dec order, push in ans
            for (int i = rmax, j = cmax; j >= cmin && tr < n*m; j--){
                ans.push_back(a[i][j]);
                tr++;
            }
            // rmax--, this shift the bottom borders upwards as we need not traverse this again
            rmax--;
            
            // 1st col traverse 
            for (int i = rmax, j = cmin; i >= rmin && tr < n*m; i--){
                ans.push_back(a[i][j]);
                tr++;
            }
            cmin++;
        } 
        return ans;
        
    }
};
