class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int n = s1.size(), m = s2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // since we use only prev row so 2d dp ->2 1d dp to store prev and curr row
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; j++) prev[j] = j;   // base case 1

        for (int i = 1; i <= n; i++) {
            curr[0] = i;                            // base case 2 
            for (int j = 1; j <= m; j++) {

                // CASE 1
                if (s1[i - 1] == s2[j - 1])     
                    curr[j] = prev[j - 1];
                
                // CASE 2
                else 
                    curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
            }
            prev = curr;
        }
        return prev[m];
    }
};
/* else case taking all seprately
int del = 1 + prev[j];    
int ins = 1 + curr[j - 1];  
int rep = 1 + prev[j - 1];  

curr[j] = min(del, min(ins, rep));
*/
