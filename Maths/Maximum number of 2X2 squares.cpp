// https://practice.geeksforgeeks.org/problems/maximum-number-of-22-squares/1

class Solution
{
    public:
    long long int numberOfSquares(long long int base)
    {
        // n will tell us the no. of squares in the base
        // like for base = 8, n = 3, as in base there are 3 squares
        long long int n = (base/2) - 1;
        
        // we can see from diag the no. of squares decrease as we go from base to top
        // so no. of sq decreae like 3 .. 2 .. 1 ..
        // so ans will be sum of natural no.s from 1 to n for n>0
        if (n > 0)
            return n*(n+1)/2;
            
        return 0;
    }
};
