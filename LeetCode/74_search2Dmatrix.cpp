// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        
        int n = a.size() - 1;
        int m = a[0].size() - 1;
        int row = 0;
        int low = 0;
        int high = n;
        int mid;
        
        // binary search 
        // find the row in which the target ight be present
        while (low<=high){
            
            mid = low + (high-low)/2;
            
            if (a[mid][0] <= target && target <= a[mid][m])     break;
            else if (a[mid][0] < target)                        low = mid+1;
            else                                                high = mid-1;
            
        }
        
        // mid will have the row where el might be present
        row = mid;
        low = 0, high = m;
        
        // binary search in the row to find the answer
        while (low<=high){
            
            mid = low + (high-low)/2;
            
            if (a[row][mid] == target) return true;
            else if (a[row][mid] < target) low = mid+1;
            else high = mid-1;
            
        }
        return false;   
    }
};
