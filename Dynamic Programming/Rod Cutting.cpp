// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
// https://takeuforward.org/data-structure/rod-cutting-problem-dp-24/
class Solution{
  public:
/*
Price[]  = {1, 5, 8, 9, 10, 17, 17, 20}
Length[] = {1, 2, 3, 4,  5,  6,  7,  8}
N = 8

we need to find max price we can attain taking diff lengths where sum == N
so it is similiar to knapsack with duplicate items as we can take one length multiple times
https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
best code taken from above solution 

here we can make length at particlular index to be (i + 1) as it is increasing
so we dont need to make a seprate length array so weight array in knapsack --> i + 1 's
*/  
    int cutRod(int val[], int n) { // val[ == price[]
        
        vector<int> curr(n+1, 0);
        
        for (int i = 1; i <= n; i++)
            curr[i] = val[0]*(i);
        
        // 2 loops as 2 indices to deal with i and w
        // i start from 1 as 0 taken in base case
        // paste the memo codewith changes
        for (int i = 1; i < n; i++) {
            for (int w = 0; w <= n; w++) {
                
                int notTake = 0 + curr[w];
                int take = -1;
                if ((i + 1) <= w) take = val[i] + curr[w - (i + 1)];
                
                curr[w] = max(take, notTake);
            }
        }
        return curr[n];
    }
};
