// https://practice.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1
// https://www.geeksforgeeks.org/find-the-two-numbers-with-odd-occurences-in-an-unsorted-array/
// READ EXPLANATION ABOVE

class Solution {
    public:
    vector<int> twoOddNum(int a[], int n) {
        
        // fiding xor of all numbers in arr in xor2
        int xor2 = 0;
        for (int i = 0; i < n; i++) xor2 = xor2 ^ a[i];
        
        // now find the rightmost set bit position in xor2
        // ex. if xor2 is 10110 --> we need 00010 in right_set_bit
        // ~xor2 --> 01001 --> +1 --> 01010
        // & both --> (10110 & 01010) --> 00010
        // ((~xor2) + 1) this is 2's complement
        int right_set_bit = xor2 & ((~xor2) + 1);
        
        // x and y hold both numbers 
        int x = 0, y = 0;
        
        // when we have 1 in xor of 2 numbers we know that in both numbers that place' bit will be different
        // so after finding rightmost set bit we know that one number will have that and one wont
        // so we divide our array in 2 groups, one having that set bit and one that do not have
        // all even occ numbers will come in pairs in each group
        // so do xor of both groups and we will get our ans
        for (int i = 0; i < n; i++) {
            if (a[i] & right_set_bit)   // group 1 with all set bits at right_set_bit
                x = x ^ a[i];
            else                        // group 2    
                y = y ^ a[i];
        }
        // place greater number 1st in ans vector
        return (x > y) ? vector<int>{x, y} : vector<int>{y, x};
    }
};
