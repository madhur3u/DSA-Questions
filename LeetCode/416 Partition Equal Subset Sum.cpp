class Solution {
public:
    bool canPartition(vector<int>& arr) {

        int n = arr.size();
        int numSum = accumulate(arr.begin(), arr.end(), 0);   // sum of all el of nums

        // if sum is odd we cannot part it into two equal parts, two parts can never have equal sums
        if (numSum % 2 == 1) return false;

        // now we know sum is even
        // what we need to find is a subset with sum == k (half of total sum)
        // since if we can find a subset of half sum then the other subset left will have same other half sum
      
        // QUESTION REDUCED TO CHECK IF SUBSET EXIST WITH SUM = K
        // https://github.com/madhur3u/DSA-Questions/blob/main/Dynamic%20Programming/Subset%20Sum%20Problem
        // all solutions for that problem we use most efficient soln here
        int k = numSum / 2;     
        vector<bool> prev(k+1, 0), curr(k+1, 0);

        prev[0] = curr[0] = true;
        if (arr[0] <= k) prev[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= k; target++) {

                bool notTake = prev[target]; 
                bool take = false;
                if (arr[i] <= target) take = prev[target - arr[i]];
                
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[k]; 
    }
};
