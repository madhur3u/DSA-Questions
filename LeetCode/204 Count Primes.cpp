// https://www.geeksforgeeks.org/sieve-of-eratosthenes/

class Solution {
public:
    int countPrimes(int n) {
        
        // if 0 or 1 then return 0
        if (n == 0 || n == 1) return 0;

        // since we need numbers less than n so subtract 1 from n 
        n = n - 1;

        // using Sieve of Eratosthenes make a bool array for n values set all equal to true
        bool prime[n + 1];
        memset(prime, true, n + 1);

        // initial count of all true, since 1 is not prime hence subtract 1
        int count = n - 1;

        // taking all nums from 2 till root(n)
        for (int num = 2; num*num <= n; num++){
            
            // if the current num is set true
            // set all of its multiples from num*num till n to false
            // if we are changing a value from true to false, decrease count as this is not a prime anymore
            if (prime[num]){
                for (int i = num*num; i <= n; i +=num){
                    if (prime[i]){
                        prime[i] = false;
                        count--;
                    } 
                }
            }
        }
        // count will now have count of all primes less than n
        return count;
    }
};
