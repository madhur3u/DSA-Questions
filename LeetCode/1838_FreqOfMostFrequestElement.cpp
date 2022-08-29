// https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// https://www.youtube.com/watch?v=vgBrQ0NM5vE

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        // sort the array so we can use sliding window concept
        // this make the t.c. logN
        sort(nums.begin(), nums.end());   
        
        // low and high are the pointers which tell us about our current window
        // current sum is the sum of elements in our current window
        // ans has the no. of elements which can get us the desired result
        int low = 0, high = 0; 
        long current_sum = 0;
        int ans = 1;
        
        // O(N) traversal
        while (high < nums.size()){
            
            // getting value of sum of elements in current window, only high as at first hi lo same pos
            current_sum += nums[high];
            
            // now we have k increases to make all elements in window equal
            // so we can first find the max sum which we can achive in current window
            // by making all elements equal to the rightmost el in window, as we can only add and no subtract
            // max sum = (long)(high - low + 1)*(long)nums[high]) long to prevent int overflow
            // in while loop we check if condition do not meet desired result ans reduce window length till we get desired result
            while ((long)(k + current_sum) < (long)(high - low + 1)*(long)nums[high]){
              
                // reducing current sum as we have to reduce window length
                current_sum -= nums[low];
                low++;
            }
          
            // when we are out of loop we have satisfied our condition
            // so update ans and inc hingh to change window length for next itertion
            ans = max(ans, high-low+1);
            high++;
        }
        return ans;
        
    }
};
/*
Intuition

Sort the input array A
Sliding window prolem actually,
the key is to find out the valid condition:
k + sum >= size * max
which is
k + sum >= (j - i + 1) * A[j]

Explanation

For every new element A[j] to the sliding window,
Add it to the sum by sum += A[j].
Check if it'a valid window by
sum + k < (long)A[j] * (j - i + 1)

If not, removing A[i] from the window by
sum -= A[i] and i += 1.

Then update the res by res = max(res, j - i + 1).

I added solution 1 for clearly expain the process above.
Don't forget to handle the overflow cases by using long.
*/

//ALTERNATE CODE https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175090/JavaC%2B%2BPython-Sliding-Window
// rather than making current sum we can store that value in K

int maxFrequency(vector<int>& A, long k) {
        int i = 0, j;
        sort(A.begin(), A.end());
        for (j = 0; j < A.size(); j++) {
            k += A[j];
            if (k < (long)A[j] * (j - i + 1))
                k -= A[i++];
        }
        return j - i;
    }
