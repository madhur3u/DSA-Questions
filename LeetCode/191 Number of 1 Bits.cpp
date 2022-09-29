class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        // this will hold ans
        int count = 0;
        
        while (n){
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};

/*
If we have number n, then n&(n-1) will remove the rightmost in binary representation of n. 
For example if n = 10110100, then n & (n-1) = 10110100 & 10110011 = 10110000, where & means bitwise operation and. 
Just repeat this operation until we have n = 0 and count number of steps.

for n = 1 1 0 1 1

1st pass -> 1 1 0 1 1
            1 1 0 1 0 these both will & gives --> 1 1 0 1 0 , count = 1

2ns pass -> 1 1 0 1 0
            1 1 0 0 1 these both will & gives --> 1 1 0 0 0 , count = 2

3rd pass -> 1 1 0 0 0
            1 0 1 1 1 these both will & gives --> 1 0 0 0 0 , count = 3

4th pass -> 1 0 0 0 0
            0 1 1 1 1 these both will & gives --> 0 0 0 0 0 , count = 4
            
it will only take 4 pass the starting zeroes does not matter as n & n - 1 removes rightmost set bits
so when all 4 removed n = 0

Complexity It is O(1) for sure, because we need to make no more than 32 operations here, but it is quite 
vague: all methods will be O(1), why this one is better than others? In fact it has complexity O(m), where m
is number of 1-bits in our number. In average it will be 16 bits, so it is more like 16 operations, not 32 
here, which gives us 2-times gain. Space complexity is O(1)
*/
