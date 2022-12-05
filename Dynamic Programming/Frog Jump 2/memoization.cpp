// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

int dfs(int idx, vector<int>& heights, int k, vector<int>& dp) {

    if (idx == 0) return 0;             // base case
    if (dp[idx] != -1) return dp[idx];  // if ans already stored previously

    int jumpMin = INT_MAX;  // min jump from ith index till (i - k)th index 

    // taking all k jumps from 1 jump till k jump
    // also taking valid indices if jump result in -ve indices we dont take that jump
    // therefore we add idx - i >= 0
    for (int i = 1; i <= k && idx - i >= 0; i++) {

        // for each jump, dfs to the position we jumping and add abs heights diff to it
        int currJump = dfs(idx - i, heights, k, dp) + abs(heights[idx] - heights[idx - i]);

        // take min of all jumps
        jumpMin = min(jumpMin, currJump);
    }

    // return min jump also store it in dp array : memoization
    return dp[idx] = jumpMin;
}

int solve(int n, vector<int>& heights, int k) {

    vector<int> dp(n, -1);              // dp vector for memo
    return dfs(n - 1, heights, k, dp);  // return after dfs
}

int main() {

    vector<int> height{40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    int n=height.size();
    int k=4;

    cout<<solve(n, height, k);
}
