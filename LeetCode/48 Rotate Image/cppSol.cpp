// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    
    // this fn transpose the vector in place
    void transpose(vector<vector<int>> &a){
        for (int i = 0; i<a.size(); i++){
            for (int j = i; j<a[0].size(); j++){
                int temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
            }
        }
    }
    
    // fn to reverse a 1d array in place
    void reverse(vector<int>& arr){
        
        int low = 0, high = arr.size()-1;
        
        while (low<high){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            
            low++;
            high--;
        }
    } 
    
    void rotate(vector<vector<int>>& a) {
        
        // for 90 deg clockwise rotate first transpose the matrix
        transpose(a);
        
        // after that reverse each row 
        for (int i = 0; i<a.size(); i++){
            reverse(a[i]);
        } 
    }
};
