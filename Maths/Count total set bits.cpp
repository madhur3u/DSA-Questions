// https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n-set-2/

/*
Decimal	E	D	C	B	A
    0	0	0	0	0	0
    1	0	0	0	0	1
    2	0	0	0	1	0
    3	0	0	0	1	1
    4	0	0	1	0	0
    5	0	0	1	0	1
    6	0	0	1	1	0
    7	0	0	1	1	1
    8	0	1	0	0	0
    9	0	1	0	0	1
    10	0	1	0	1	0
    11	0	1	0	1	1
    12	0	1	1	0	0
    13	0	1	1	0	1
    14	0	1	1	1	0
    15	0	1	1	1	1
    16	1	0	0	0	0


*/
class Solution{
    public:
    int countSetBits(int n) {
        
        int power2 = 1;
        n = n + 1;
        int ans = 0;
        
        // run loop till it reach the prev nearest power of 2 and not breach that
        while (power2 <= n){
            
            // groups of 0s and 1s
            // in A till 14 we have 15 groups, 8 gropus of zero and 7 of 1
            // in B till 14 we have 7 complete groups, 4 of 0 0 and 3 of 1 1
            int groups = n / power2;
            
            // adding the no. of 1s we have acc to groups
            // for b since we have 7 groups 7 / 2 --> 3 * 2 --> 6 1's we will be having
            // no. of 1s in groups depeneds on power of 2
            ans += (groups / 2) * power2;
            
            // in case of odd groups we might leave behind some 1's eg. in 14
            // for B we should have 7 1's, but above eq give us 6
            // so if the no. of groups are odd, means last group was of 0's we include the remaining 1
            // using n % power2, else add 0 no effect
            ans += (groups & 1) ? (n % power2) : 0;
            
            // check for next power // left shift
            power2 = power2 << 1;
        }
        return ans;
    }
};
/*
Check the pattern of Binary representation of the numbers from 1 to N in the following table: 
 
Decimal	E	D	C	B	A
    0	0	0	0	0	0
    1	0	0	0	0	1
    2	0	0	0	1	0
    3	0	0	0	1	1
    4	0	0	1	0	0
    5	0	0	1	0	1
    6	0	0	1	1	0
    7	0	0	1	1	1
    8	0	1	0	0	0
    9	0	1	0	0	1
    10	0	1	0	1	0
    11	0	1	0	1	1
    12	0	1	1	0	0
    13	0	1	1	0	1
    14	0	1	1	1	0
    15	0	1	1	1	1
    16	1	0	0	0	0


Notice that, 
 

    Every alternate bits in A are set.
    Every 2 alternate bits in B are set.
    Every 4 alternate bits in C are set.
    Every 8 alternate bits in D are set.
    .....
    This will keep on repeating for every power of 2.


So, we will iterate till the number of bits in the number. And we don't have to iterate every single number in the range from 1 to n. 
We will perform the following operations to get the desired result. 
 

    , First of all, we will add 1 to the number in order to compensate 0. As the binary number system starts from 0. So now n = n + 1.
    We will keep the track of the number of set bits encountered till now. And we will initialise it with n/2.
    We will keep one variable which is a power of 2, in order to keep track of bit we are computing.
    We will iterate till the power of 2 becomes greater than n.
    We can get the number of pairs of 0s and 1s in the current bit for all the numbers by dividing n by current power of 2.
    Now we have to add the bits in the set bits count. We can do this by dividing the number of pairs of 0s and 1s by 2 which will give us the 
    number of pairs of 1s only and after that, we will multiply that with the current power of 2 to get the count of ones in the groups.
    Now there may be a chance that we get a number as number of pairs, which is somewhere in the middle of the group i.e. the number of 1s are 
    less than the current power of 2 in that particular group. So, we will find modulus and add that to the count of set bits which will be clear 
    with the help of an example.


Example: Consider N = 14 
From the table above, there will be 28 set bits in total from 1 to 14. 
We will be considering 20 as A, 21 as B, 22 as C and 23 as D
First of all we will add 1 to number N, So now our N = 14 + 1 = 15. 
 ^ represents raise to the power ,not XOR.

eg. 2^3 means 2 raise to 3.

    Calculation for A (20 = 1) 
    15/2 = 7 
    Number of set bits in A = 7 ------------> (i)
    Calculation for B (2^1 = 2) 
    15/2 = 7 => there are 7 groups of 0s and 1s 
    Now, to compute number of groups of set bits only, we have to divide that by 2. 
    So, 7/2 = 3. There are 3 set bit groups. 
    And these groups will contain set bits equal to power of 2 this time, which is 2. So we will multiply number of set bit groups with power of 2 
    => 3*2 = 6 --->(2i) 
    Plus 
    There may be some extra 1s in this because 4th group is not considered, as this division will give us only integer value. So we have to add that 
    as well. Note: - This will happen only when number of groups of 0s and 1s is odd. 
    15%2 = 1 --->(2ii) 
    2i + 2ii => 6 + 1 = 7 ------------>(ii)
    Calculation for C (2^2 = 4) 
    15/4 = 3 => there are 3 groups of 0s and 1s 
    Number of set bit groups = 3/2 = 1 
    Number of set bits in those groups = 1*4 = 4 ---> (3i) 
    As 3 is odd, we have to add bits in the group which is not considered 
    So, 15%4 = 3 ---> (3ii) 
    3i + 3ii = 4 + 3 = 7 ------------>(iii)
    Calculation for D (2^3 = 8) 
    15/8 = 1 => there is 1 group of 0s and 1s. Now in this case there is only one group and that too of only 0. 
    Number of set bit groups = 1/2 = 0 
    Number of set bits in those groups = 0 * 8 = 0 ---> (4i) 
    As number of groups are odd, 
    So, 15%8 = 7 ---> (4ii) 
    4i + 4ii = 0 + 7 = 7 ------------>(iv)


At this point, our power of 2 variable becomes greater than the number, which is 15 in our case. (power of 2 = 16 and 16 > 15). 
So the loop gets terminated here. 
Final output = i + ii + iii + iv = 7 + 7 + 7 + 7 = 28 
Number of set bits from 1 to 14 are 28.
*/
