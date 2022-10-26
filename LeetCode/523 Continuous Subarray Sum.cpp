// https://www.youtube.com/watch?v=OKcrLfR-8mE

/*
    nums       = [23, 2, 4, 6, 7]  k = 6
    prefix sum = [23,25,29,35,42]
    remainder  = [ 5, 1, 5, 5, 0]  remainder when prefix sum divided by k

    mathematically we can prove that if we see same remainder (x) one more time it means that between prev 
    index where x was remainder and current index we will have elements sum % k
    as we can see in above ex -> 23 rem is 5
    then 9 rem also -> 5
    and between them we have 2, 4 whose sum == 6, a multiple of k

    so for each index we find prefix sum and its rem with k, we check if we have seen this rem before
    rem and index will be stored in a hashmap so we can check if length of subarray is at least > 2
    if we dont find rem we push rem : index pair to map

    EDGE CASE - 
    nums = [6, 12] k = 6
    prfs = [6, 18] 
    rem  = [0, 0]

    if we do this with above method we push 0 : 0 for first rem
    for secod we check but i - psr[i] == 1 so we do not return true and loop ends
    so when we have a case when 0 rem might be in 1st index we push {0 : -1} already in map
    this way we can handle this edge case
                 
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map <int, int> psr; // prefix sum remainder map O(k)
        
        // edge case handling
        psr[0] = -1;
        int prefix_sum = 0;

        // iterate in array
        for (int i = 0; i < n; i++) {

            // update prefix sum and rem
            prefix_sum += nums[i];
            int rem = prefix_sum % k;

            // check in map and check subarray length
            if (psr.find(rem) != psr.end()){
                if (i - psr[rem] >= 2) return true;
            }
            // if not found add in map
            else psr[rem] = i; 
        }
        return false;
    }
};
