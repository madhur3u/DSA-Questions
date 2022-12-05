// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& heights, int k) {

    vector<int> dp(n);      // dp vector for memo
    dp[0] = 0;              // base case

    // bottom up from 1 till n
    for (int idx = 1; idx < n; idx++) {

        // calculate jumpMin for curr idx from states already stored in prev indices
        int jumpMin = INT_MAX; 
        for (int i = 1; i <= k && idx - i >= 0; i++) {

            int currJump = dp[idx - i] + abs(heights[idx] - heights[idx - i]);
            jumpMin = min(jumpMin, currJump);
        }
        // update dp array with min jump
        dp[idx] = jumpMin;
    }

    return dp[n - 1];  
}

int main() {

    vector<int> height{40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    int n=height.size();
    int k=4;

    cout<<solve(n, height, k);
}
