class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        // XOR of both no. will give us set bits in places where bits are different
        // so we need to flip no. of sets bits in xor of both numbers
        int x = start ^ goal;

        // count no. of set bits to get ans
        return __builtin_popcount(x);
    }
};
/*
code to count no. of set bits

    int ans = 0;
    while (x){
        x = x & (x - 1);
        ans++;
    }
*/
