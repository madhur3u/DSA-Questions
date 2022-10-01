class Solution {
public:
    int numDecodings(string s) {
        
        // empty string or first value 0, means cant decode string
        if (s.empty() || s[0] == '0') return 0;

        int n = s.size();

        // we make a vector which store no. of ways till an index in it DP
        // set its 0th and 1st index to 1 as we make our ans b adding previous 2 idx value
        // so for s = '12', we will have ways_to_decode[i + 1] = ways_to_decode[i] + ways_to_decode[i - 1];
        // so for 2, we have 1 + 1 ways one which we store in 0th index and 1 way as using 1 we have one way
        vector<int> ways_to_decode(n + 1, 0);
        ways_to_decode[0] = 1;
        ways_to_decode[1] = 1;

        // start decoding from 1st index of s as for 0th index we have 1 way to decode already stored in decode[1]
        for (int i = 1; i < s.size(); i++) {
            
            // taking out curr and prev value
            int curr = s[i] - '0';
            int prev = s[i - 1] - '0';

            // case when string cannot be decoded we return 0
            // if both '00' or '60', '30' which is > 26
            if ((prev == 0 && curr == 0) || (curr == 0 && ((prev*10 + curr) > 26)))
                return 0;
            
            // if the prev was zero so the no. of ways to decode remains same as previous ways
            // if the prev*10 + curr > 26 '56', '29' etc, then alse ways of decode same as previous ways
            else if (prev == 0 || ((prev*10 + curr) > 26))
                ways_to_decode[i + 1] = ways_to_decode[i];
            
            // if current value is zero, means it has to be mapped with previous value
            // so even if prev might have inc no. of ways to decode but we will shift two step back in ways
            // as now this zero has to be mapped with previous, so ways_to_decode[i + 1] = ways_to_decode[i - 1]; // two step back
            else if (curr == 0)
                ways_to_decode[i + 1] = ways_to_decode[i - 1];

            // for all valid combination ex, '12', '25', no. of ways = prev 2 ways
            else 
                ways_to_decode[i + 1] = ways_to_decode[i] + ways_to_decode[i - 1];
        }
        // return the last value of decode vector, which will be the ans
        return *ways_to_decode.rbegin();
    }
};

/*  EXAMPLES decode array with string

s = "1 2 3 6 9 1 0 1 4"
   1 1 2 3 3 3 3 3 3 6 decode[i + 1]
   
s = "1 2 3 6 1 1 0 1 4"
   1 1 2 3 3 3 6 3 3 6 decode[i + 1]
*/
