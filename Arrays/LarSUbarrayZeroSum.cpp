// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// So in this problem, we’ll store the prefix sum of every element, and if we observe that 2 elements have same prefix sum, 
// we can conclude that the 2nd part of this subarray sums to zero

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // weare going to find prefix sum and store it in map with the index xif its not zero
        int prefix_sum = 0;
        unordered_map<int, int> mp;
        int ans = 0;
        
        for (int i = 0; i<n; i++){
            
            // prefix sum calculation
            prefix_sum += A[i];
            
            // if prefix sum zero means sum from 0th index till now is zero
            // so this will be the biggest subarray with zero index so far
            // hence updating ans to i + 1
            if (prefix_sum == 0) 
                ans = i + 1;
            
            // if we find a prefix sum in array which we had encountered earlier
            // it means from the last index where we got the sum to current i
            // the sum will be zero, thats why we have stored the index in map with sum
            // so we update our ans with max of current length and index difference
            else if (mp.find(prefix_sum) != mp.end()) 
                ans = max (ans, i - mp[prefix_sum]);
            
            // push the prefix sum and index when no above case is true
            else 
                mp[prefix_sum] = i;
        }
        
        return ans;
    }
};


/*
One thought come our mind is whenever subarray sum is equal to zero , We get one hint →
Let's understand with example                  0    1   2    3   4   5   6   7
Suppose our input array is →                  {15, -2,  2,  -8,  1,  7,  10, 23}
Ok let's write prefix sum of this array →     {15,  13, 15,  7,  8,  15, 25, 48}
You can see index (prefix array) → 0 and 2 element are same and 0 and 5 element are also same . 
This means between these indexes subarray sum ( in original array ) is zero . 
How we can sure that ??? 
If you add something in number and remove also . the number initially and last are same . 
We can use this approach and solve this problem efficiently . 
For search in prefix array → use HashMap .
The sum-index pair will be stored in a hash-map. A Hash map allows insertion and deletion of key-value pair in constant time. 
Therefore, the time complexity remains unaffected. So, if the same value appears twice in the array, it will be guaranteed that 
the particular array will be a zero-sum sub-array. 

Approach: 

    First let us initialise a variable say sum = 0 which stores the sum of elements traversed so far and another variable say max = 0 
    which stores the length of longest subarray with sum zero.
    Declare a HashMap<Integer, Integer> which stores the prefix sum of every element as key and its index as value.
    Now traverse the array, and add the array element to our sum. 

 (i)  If sum = 0, then we can say that the subarray until the current index has a sum = 0,      
      so we update max with the maximum value of (max, current_index+1)

(ii)  If sum is not equal to zero then we check hashmap if we’ve seen a subarray with this sum before

if HashMap contains sum -> this is where the above-discussed case occurs (subarray with equal sum), so we update our max 

else -> Insert (sum, current_index) into hashmap to store prefix sum until current index

    After traversing the entire array our max variable has the length of longest substring having sum equal to zero, so return max.

NOTE : we do not update the index of a sum if it’s seen again because we require the length of the longest subarray
*/
