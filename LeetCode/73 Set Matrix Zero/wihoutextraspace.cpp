// https://leetcode.com/problems/set-matrix-zeroes/

// Instead of taking two dummy arrays we can use the first row and column of the matrix for the same work. 
// This will help to reduce the space complexity of the problem. While traversing for the second time the 
// first row and column will be computed first, which will affect the values of further elements that’s why 
// we traversing in the reverse direction.

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        
        // we make 2 bools from 1st row and col if anything in it iz zero
        // we do not update the row itself as it will store zeroes from middle of array
        bool row1 = false;
        bool col1 = false;
        
        int n = a.size();
        int m = a[0].size();
        
        for (int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                
                if (a[i][j] == 0){
                    
                    // if 1st el is 0 set both flags as true
                    if (i == 0 && j == 0) row1 = col1 = true;
                    
                    // if we encounter a zero at 1st row we just true row flag
                    // dont need to update row value as in 1st row it is already zero
                    else if (i == 0) row1 = true;
                    
                    // if zero in 1st col true col1 flag 
                    // no need to update col value as already zero
                    else if (j == 0) col1 = true;
                    
                    // if zero in middle part of array
                    // set the 1st row's that value 0 and 1t col that value as 0
                    else {
                        a[0][j] = 0;
                        a[i][0] = 0;
                    }
                }
            }
        }
        
        // now our 1st row and 1st col will act like the extra space which we use
        // if we have zero in any place in 1st row whole col under it will be zero
        // and in col then that whole row will have zeroes
        
        // we do not take 1st row and col as it will be handled by flags row1 col1
        for (int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                
                // for any element if corresponding el of either 1st row OR 1st col is zero
                // set that el to zero
                if (a[0][j] == 0 || a[i][0] == 0) {
                    a[i][j] = 0;
                }
            }
        }
        
        // now if row1 was set
        // make the whole 1st row zero
        if (row1){
            for (int j = 0; j<m; j++){
                a[0][j] = 0;
            }
        }
        
        // if col1 set make whole 1st col as zero
        if (col1){
            for (int i = 0; i<n; i++){
                a[i][0] = 0;
            }
        }
    }
};

// Space - O(1) as we made only two bool variables which is constant space
// Time -   O(n*m) for 1st traversal when we set flags and 1st row col values
//          O(n-1*m-1) for setting zeroes in middle of array
//          O(m) for setting 1st row
//          O(n) for setting 1st col
// Total -> O(2*n*m) --> O(n*m)
