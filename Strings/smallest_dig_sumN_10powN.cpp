// https://practice.geeksforgeeks.org/problems/smallest-number-with-sum-of-digits-as-n-and-divisible-by-10n4032/1


class Solution{
	public:
	string digitsNum(int N)
	{   
        // stores the ans
	    string ans = "";
	    
        // find the remained and quotient
	    int rem = N % 9;
	    int quo = N / 9;
	    
        // forming the smallest no. first with sum N and place in starting of ans
        // add rem when not zero
	    if (rem) ans = ans + to_string(rem);
	    // add no. of nines acc to quotient
	    while (quo) {
	        ans = ans + "9";
	        quo--;
	    }
        
        // we also need to add N zeroes
	    for (int i = 1; i <=N; i++) ans = ans + "0";
	    
	    return ans;
    }
};

/* list of smallest no with sum n

1 1
2 2
. . 
8 8
9 9

10 19
11 29
12 39
13 49
. .
17 89
18 99

19 199
20 299
21 399
. .
26 899
27 999

28 1999
29 2999 ans so on...

so the 1st number is always the remainder when divided by nine (except when rem is 0)
and the quotient will tell us the no. of nines to be pushed in end

ex. 26 % 9 --> 8
    26 / 9 --> 2 
    so no. will be 899
*/
