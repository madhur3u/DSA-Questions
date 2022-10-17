/*
total subarrays - no. of subarray with at most 2 diff elements (out of a b c)
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();

        // totoal no. of subarrays can be found mathematically
        long long totalSubarray = ((long long)n * (n + 1)) >> 1;

        // array to hold freq of a b c, since 3 space used so O(1)
        int arr[3] = { 0 };
        long long res = 0;

        // sliding winodow
        // in res we find no. of subarray with at most 2 diff characters so no a b c together
        for(int l = 0, r = 0; r < n; r++) {
            
            // inc index of whatever found
            arr[s[r] - 'a']++;

            // for at most 2 element to be diff, all 3 will never have a value, one will atleast be zero
            // so if not dec winodw length from left and dec count till condition fulfilled
            while (arr[0] != 0 && arr[1] != 0 && arr[2] != 0) {
                arr[s[l] - 'a']--;
                l++;
            }
            // add all subarrays with at most 2 diff elements in result from l to r
            res += (r - l + 1);
        }
        // ans = total - atmost2
        return totalSubarray - res;
    }
};
