// https://practice.geeksforgeeks.org/problems/distributing-question-papers2513/1

class Solution {
public:
int MinimumExchange(vector<vector<char>>a){
    
    int n = a.size();
    int m = a[0].size();
    
    // ans 1 hold exchanges needed if we make matrix as ABAB....
    int ans1 = 0;
    char ch;
    
    // iterate in whole matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            
            // for ABAB.. every character having even value of i + j will have A
            // and odd values will have B, so assinging ch accordingly
            if ((i + j) % 2 == 0) ch = 'A';
            else ch = 'B';
            
            // check if matrix dont has that character, add this to ans
            // as this character not in correct pos we need to change its pos
            if (a[i][j] != ch) ans1++;
        }
    }
    // ans 2 hold exchanges needed if matrix is BABABABA......
    int ans2 = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            
            // for BABA.. i + j even value have B, reverse of above
            if ((i + j) % 2 == 0) ch = 'B';
            else ch = 'A';
            
            // find all which are not in correct pos
            if (a[i][j] != ch) ans2++;
        }
    }
    
    // both ans1, and ans2 have exchanges we need to make matrix what we need
    // we return min of both
    return min(ans1, ans2);
}
};
