// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &h) {
    
    int prev1 = 0;           // if (i == 0) return 0; base case
    int prev2 = 0;
    
    // bottom up approach, we took base case first now will go from 1 till top -> n
    for (int i = 1; i < n; i++) {
        
        int jump1, jump2 = INT_MAX;
        
        // jump 1, take 1 step and add height diff in 1 step
        jump1 = prev1 + abs(h[i] - h[i - 1]);

        // jump 2 only when index > 1 as we dont want to take -1 case when i = 1
        // add height diff of 2 jumps using heights array h
        if (i > 1) jump2 = prev2 + abs(h[i] - h[i - 2]);
        
        int curr = min(jump1, jump2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
