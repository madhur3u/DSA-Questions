// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
#include <bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points) {
    
    // since we need only states saved for last day or day - 1
    // so we dont need a 2d dp
    // we can do it using only 1d dp of 4 size for all 4 states
    vector<int> dp(4);
    
    // base case, for 0th day we need to save max of other left tasks
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));  
    
    for (int day = 1; day < n; day++) {              // days from 1 to n
        vector<int> temp(4);                         // temp array to store curr day states
        for (int last = 0; last < 4; last++) {       // this loop tell us what last task we did
            
            int maxP = 0;
            for (int task = 0; task < 3; task++) {    // tasks loop from 0 to 3
                if (task != last) maxP = max(maxP, points[day][task] + dp[task]);
            }
            temp[last] = maxP;
        }
        dp = temp;    // save curr day states in dp
    }
    return dp[3];
}
