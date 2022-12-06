// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
#include <bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points) {
    
    vector<vector<int>> dp(n, vector<int>(4));
    
    // base case, for 0th day we need to save max of other left tasks
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));  
    
    for (int day = 1; day < n; day++) {            // days from 1 to n
        for (int last = 0; last < 4; last++) {     // this loop tell us what last task we did
            
            int maxP = 0;
            for (int task = 0; task < 3; task++) {    // tasks loop from 0 to 3
                // dont take task already done in last day
                if (task != last) maxP = max(maxP, points[day][task] + dp[day - 1][task]);
            }
            // update task in dp
            dp[day][last] = maxP;
        }
    }
    return dp[n - 1][3];
}
