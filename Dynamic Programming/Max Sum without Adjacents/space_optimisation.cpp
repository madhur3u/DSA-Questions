// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
class Solution{
public:	
	int findMaxSum(int *arr, int n) {

	    int prev1 = arr[0]; // 1st state save in prev
	    int prev2 = 0;      // we need 2 prev
	    
	    // bottom up approach
	    for (int i = 1; i < n; i++) {
	        
	        // if we pich ith element
	        // we ad prev2 only when its exist
            int pick = arr[i];
            if (i > 1) pick += prev2;
            
            // not picking curr ith el, we pick the max already stored in prev1
            int non_pick = prev1;
            
            // find max of pick and non pick
            int currMaxSum = max(pick, non_pick);
            prev2 = prev1;          // save prev with new states
            prev1 = currMaxSum;
        }

        return prev1;
    }
};
