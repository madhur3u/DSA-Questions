/*
nums1 = [1 2]
nums2 = [3 4 5]

lets see all pairs, we have to do xor of all paird i.e. nums3
(1^3)^(1^4)^(1^5)^(2^3)^(2^4)^(2^5)

we can see that everey element of nums1 appears nums2.size() time in all pairs
and every element of nums2 appears nums1.size() time

so since we know xor even occuring is 0 and odd occuring is number itself
so we can check for length of first array and do xor of another array if the 1st array length is odd and vv
*/

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int ans = 0;

        // if length of 2nd array is odd
        // xor all elements of nums1
        if (nums2.size() & 1){
            for (int n : nums1) ans = ans ^ n;
        }
        // if length of 1st array is odd
        // xor all elements of nums2
        if (nums1.size() & 1){
            for (int n : nums2) ans = ans ^ n;
        }
        return ans;
    }
};

/*
Intuition

ai ^ b1, ai ^ b2, ai ^ b3....
ai will construct B.length pairs
bi will construct A.length pairs

Explanation

If B.length is even,
ai will xor even times,
and equal to 0.

If B.length is odd,
ai will xor odd times,
and equal to ai.

Same for bi

If A.length is even and B.length is even,
res = 0

If A.length is odd and B.length is even,
res = B[0] ^ B[1] ^ ...

If A.length is even and B.length is odd,
res = A[0] ^ A[1] ^ ...

If A.length is even and B.length is even,
res = A[0] ^ A[1] ^ ... ^ B[0] ^ B[1] ^ ...

Complexity

Time O(n)
Space O(1)
*/
