// https://leetcode.com/problems/find-a-peak-element-ii/
// DRY RUN

/*The algorithm is as follows:

    Pick the middle row.
    Find the global maximum in the row.
    If the col-neighbours of this element are smaller, then we found a 2D peak. Else, we recurse at the top-half of the matrix if the top-neighbour was bigger, and bottom-half of the matrix if the bottom-neighbour was bigger.
*/

class Solution {
public:
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int lo = 0, hi = n - 1;
        
        // in row we use divide and conquer approach
        while (lo <= hi){
            
            int mid = (lo + hi) >> 1;
            
            // finding the max element in current row and storing its index in maxCol
            int maxCol = 0;
            for (int j = 0; j<m; j++){
                if (mat[mid][maxCol] < mat[mid][j]) maxCol = j;
            }
            
            // if (mid == 0 && mat[mid][maxCol] > mat[mid + 1][maxCol]) return {mid, maxCol};
            // else if (mid == n - 1 && mat[mid][maxCol] > mat[mid - 1][maxCol]) return {mid, maxCol};
            // else if (mid != 0 && mid != n - 1 && mat[mid][maxCol] > mat[mid + 1][maxCol] && mat[mid][maxCol] > mat[mid - 1][maxCol]) 
            //     return {mid, maxCol};
            
            // at the end our lo and hi both points to same row
            // where the peak el is present hence return ans
            if (lo == hi) return {mid, maxCol};
            
            // if at the bottom row we found an element bigger than max in this row
            // we will discard top half
            else if (mat[mid + 1][maxCol] > mat[mid][maxCol]) lo = mid + 1;
            
            // if a bigger element is found at upper half or not found(means in current row we found ans)
            // update hi as mid so that our current row is safe and we will be able to check the top half
            // we are doing this to get rid of all if statements in the comments above
            else hi = mid;
        }
        return {-1, -1};
    }
};
