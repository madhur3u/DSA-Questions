// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// https://www.youtube.com/watch?v=ttlNQ6YrdGs

class Solution {
public:
    int concatenatedBinary(int n) {
        
        // declaring ans and mod variable
        long long ans = 0;
        int mod = 1000000007;
        
        // running the loop from 1 to N
        for (int i = 1; i<=n; i++) {
            
            // find the no. of bits in binary which i will have
            // ex. 1 --> 1, 5 --> 3, 8 --> 4
            int no_of_bits = 1 + log2(i);
            
            // the logic is we left shift the ans by no. of digits and then add i to ans
            // for 1 --> 0 << 1(no. of bits in i) --> 0 0   --> 0 + 1(binary of 1 i) --> ans = 1
            // for 2 --> 1 << 2(no. of bits in i) --> 1 0 0 --> 1 0 0 (4) + 1 0 (2) --> 1 1 0 --> ans = 6
            // for 3 --> 6 << 2(no. of bits in i) --> 1 1 0 0 0 --> 1 1 0 0 0(24) + 1 1(3) --> 1 1 0 1 1 --> ans = 27 ...
            ans = ((ans << no_of_bits) % mod + i) % mod;
        }
        return ans;
    }
};
