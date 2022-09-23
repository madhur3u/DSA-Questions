// https://leetcode.com/problems/powx-n/
// Binary Exponentiation using which we can calculate xn using O log2(N) multiplications.

class Solution {
public:
    double myPow(double x, int n) {
        
        // converting n to long for INT_MIN value as its positive is out of int range
        // convert the new n to positive
        long long N = n;
        if (n < 0) N = (-1) * N;
        
        // compute ans and return according to n's sign 
        double ans = power(x, N);
        if (n < 0) return (1.0 / ans);
        return ans;
    }
    
    // recursive logN soln to find x ^ n
    double power(double x, long long n){
        
        // base case
        if (n == 0) return 1;
        
        // compute half of power --> x ^ 16 --> x ^ 8 * x ^ 8
        double half = power(x, n/2);
        double ans = half * half;
        
        // if x is odd n/2 will leave one x eg. x^5 = x^2 * x^2
        // so we need to multiply once again by x to get x ^ 5;
        if (n % 2 == 1) ans = ans * x;
        return ans;
    }
};
