class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // using these 3 2d array we can check if all row, col, sq elements are same or not
        bool rows[9][9] = { }, cols[9][9] = { }, squares[9][9] = { };   

        // traverse in all rows and cols
        for (int r = 0; r < 9; r++) 
        for (int c = 0; c < 9; c++) {

            // if cell is empty it will have '.' we dont check anything, empty
            if (board[r][c] == '.') continue;

            // index will be the integer number at this cell
            int index = board[r][c] - '1';
            // k is used for 1st index in squares matrix, explanation below
            int k = ((int)r / 3) * 3 + (c / 3);

            // if any of the cell in the 3 arrays is true means invalid sudoku condition found
            // so we return false
            if (rows[r][index] || cols[c][index] || squares[k][index]) 
                return false;

            // else we update all cells in matrixs to be true
            rows[r][index] = cols[c][index] = squares[k][index] = true;
        }
        // if we come here means sudoku valid return true
        return true;
    }
};

/*
k = r / 3 * 3 + c / 3 
for those who need to visualize k here

0  0  0 | 1  1  1 | 2  2  2
0  0  0 | 1  1  1 | 2  2  2
0  0  0 | 1  1  1 | 2  2  2
--------+---------+---------
3  3  3 | 4  4  4 | 5  5  5
3  3  3 | 4  4  4 | 5  5  5
3  3  3 | 4  4  4 | 5  5  5
--------+----------+--------
6  6  6 | 7  7  7 | 8  8  8
6  6  6 | 7  7  7 | 8  8  8
6  6  6 | 7  7  7 | 8  8  8

k will range from 0 - 8 for each square, so we can check in each square if that number was present there
using squares[k][index]
*/
