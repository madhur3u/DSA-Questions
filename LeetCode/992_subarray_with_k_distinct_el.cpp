// https://leetcode.com/problems/subarrays-with-k-different-integers/

/*
Approach: To directly count the subarrays with exactly K different integers is hard but to find the 
count of subarrays with at most K different integers is easy. So the idea is to find the count of 
subarrays with at most K different integers, let it be C(K), and the count of subarrays with at most 
(K – 1) different integers, let it be C(K – 1) and finally take their difference, C(K) – C(K – 1) which 
is the required answer.

Count of subarrays with at most K different elements can be easily calculated through the sliding 
window technique. The idea is to keep expanding the right boundary of the window till the count of 
distinct elements in the window is less than or equal to K and when the count of distinct elements 
inside the window becomes more than K, start shrinking the window from the left till the count becomes 
less than or equal to K. Also for every expansion, keep counting the subarrays as right – left + 1 
where right and left are the boundaries of the current window.

left = i
right = j
*/

class Solution {
public:
    
    // k dist el can be found by first finding at most k elements subarray
    // then subtracat k-1, we will get exact k subarray
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n = nums.size();
        return subarrayWithAtMostK(nums, k , n) - subarrayWithAtMostK(nums, k - 1, n);
    }
    
    // this func find subarrays with at most k distinct integers
    int subarrayWithAtMostK (vector<int>& nums, int k, int n) {
        
        // base case for k - 1
        if (k == 0) return 0;
        
        // ans will hold no. of subarrays with at most k distinct integers
        int ans = 0;
        
        // i is the left pointer of our sliding window
        int i = 0;
        
        // map will hold the elements we have in our current window with their freq
        // by counting size we can check if our subarray is still valid or not
        unordered_map<int, int> mp;
        
        // j is the right pointer of our window
        for (int j = 0; j<n; j++){
            
            // add element to map and inc its freq
            mp[nums[j]]++;
            
            // this is the condition for invalid subarray
            // as no. of distinct elements has surpassed k
            // so we need to dec our sliding window length and also delete ith element from map
            // first dec freq of ith element, then check if its freq became 0
            // if its 0 means that element no more in our current window, so erase that
            // dec window width from left by i++
            while (mp.size() > k){
                
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            
            // if we are here means we have a valid subarray with atmost k distinct elements
            // add all subarrays possible between left and right pointer of window to ans
            // for [1,2,1,2,3] --> for subarray (1,2,1,2) --> there is j = 3, i = 0 so 3-0+1 = 4 subarrays
            // (1,2,1,2), (2,1,2), (1,2), (2) are the possible subarrays
            ans = ans + (j - i + 1);
        }
        return ans;
    }
};
