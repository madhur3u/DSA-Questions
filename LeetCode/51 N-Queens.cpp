// https://leetcode.com/problems/n-queens/
/*
For each row, we will place one queen (if possible within the contraint) and then move on to the next row. 
This will be repeated till all N queens have been placed. We will use the isSafe method to ensure that the 
queen is safe to place at (i, j). Once, all N queens have been placed, we have got our first solution.

Finally, to get all the other possible solutions, we will keep on removing the previously placed queen and 
try if its possible to place it at some other location, i.e, where we need to backtrack. 
This will give us all the possible combinations to place N Queens on the board as per the given constraints.

Time Complexity : O(N!), Since we have N choices in the first row, then N-1 choices in the second row and so on so the overall complexity become O(N!)
Space Complexity: O(N*N), Just the board and recursive stack space
*/

class Solution {
public:
    // global variable for result and n
    vector<vector<string>> res;
    int N;
    
    vector<vector<string>> solveNQueens(int n) {
        
        // make matrix with all blanks i.e. '.'
        vector<string> board(n, string(n, '.'));
        N = n;
        int row = 0;
        
        // send the board with 1st row index 
        solve(board, row);
        return res;
    }
    void solve(vector<string> &board, int row){
        
        // if the row index id out of range and has arrived here means we have found a solution
        // push board to res and backtrack
        if (row == N){
            res.emplace_back(board);
            return;
        }
        
        // for the current row traverse in each col, try placinf a queen if it could be placed
        // place queen and call fn again for next row, when return reove the current queen for next solution
        for (int col = 0; col < N; col++){
            
            // issafe fn will tell us if queen can be placed in the current row and col
            if (isSafe(board, row, col)){
                board[row][col] = 'Q';
                solve(board, row + 1);
                board[row][col] = '.';
            }
        }
    }
    // this fn check for a current row and col
    // if the queen is already placed in where it can attack our current queen in pper half of the board
    // since we are placing queens top to bottom hence we only need to check upper half of the board
    // we need to check the column, upper half left and right diagonal
    // do not need to check row as we are placing only one queen per row in solve funtion
    bool isSafe(vector<string> &board, int row, int col){
        
        // iterate till i = 0 till current row (upper half)
        for (int i = 0; i<=row; i++){
            
            // if a queen is found in col above current one
            if (board[i][col] == 'Q') return false;
            
            // if queen is found in left or right upper diagonal, checking for index in range first
            if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;   // left 
            if (row - i >= 0 && col + i < N  && board[row - i][col + i] == 'Q') return false;   // right
        }
        return true;
    }
};
