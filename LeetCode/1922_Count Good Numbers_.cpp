// https://leetcode.com/problems/count-good-numbers/
/*
evens  = 0, 2, 4, 6, 8  => 5 evens
primes = 2, 3, 5, 7     => 4 primes

consider for n = 4 --> we need to fill 4 places _,_,_,_
                                                0 1 2 3 
at 0 -> any 5 digits can be put -> 5 ways
at 0 -> prime ant 4 -> 4 ways and so on, so ans - > 5*4*5*4

n = 5 --> 5*4*5*4*5  --> 5**3  *  4**2 --> 5 ^ (n + 1)/2 * 4 ^ (n / 2)
*/

class Solution {
public:
    int mod = 1000000007;
    
    int countGoodNumbers(long long n) {
        return (powerMod(5, (n + 1) / 2) * powerMod(4, n / 2)) % mod;
    }
    
    // function to find power with mod in consideration
    // binary exponentiation log N
    long long powerMod (int x, long long n) {
        
        if (n == 0) return 1;
        
        long long half = powerMod(x, n/2);
        
        if (n % 2 == 0) 
            return (half * half) % mod;
        else        
            return ((half * half) % mod * x) % mod;
    }
};
