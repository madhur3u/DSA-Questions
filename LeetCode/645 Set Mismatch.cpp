/*
if we add all n numbers in the array then the question can be reworded as
find two odd occuring elements 
where duplicate will occur 3 time
and missing 1 time
we can find that by xor and rightmost set bit logic
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        int xor2 = 0;

        // find xor of all nums in array and all natural numbers till n
        // after that we will have -> xor2 = dup^dup^dup^miss -> dup^miss
        // so we need to find the dup and missing element now from xor
        int i = 1;
        for (int num : nums) xor2 ^= (i++ ^ num);

        // now find the rightmost set bit position in xor2
        // ex. if xor2 is 10110 --> we need 00010 in right_set_bit
        // ~xor2 --> 01001 --> +1 --> 01010
        // & both --> (10110 & 01010) --> 00010
        // ((~xor2) + 1) this is 2's complement
        int right_set_bit = xor2 & ((~xor2) + 1);
        int x = 0, y = 0; i = 1;

        // when we have 1 in xor of 2 numbers we know that in both numbers that place' bit will be different
        // so after finding rightmost set bit we know that one number will have that and one wont
        // so we divide our array in 2 groups, one having that set bit and one that do not have
        // all even occ numbers will come in pairs in each group
        // so do xor of both groups and we will get our ans
        for (int num : nums) {
            if (num & right_set_bit) x = x ^ num;
            else y = y ^ num;

            if (i & right_set_bit) x = x ^ i;
            else y = y ^ i;

            i++;
        }
        // now we need to find which is duplicate and missing
        // make count 0 and check how many time x occur in array
        int count = 0;
        for (int num : nums) if (num == x) count++;

        // using count return ans
        return (count) ? vector <int> {x, y} : vector <int> {y, x};
    }
};
