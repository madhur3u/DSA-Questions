// https://leetcode.com/problems/minimize-xor/solutions/2655890/set-unset-rightmost-bits-in-num1-c-100-easy-understanding/
// FOR EXPLANATION LINK ABOVE
// https://leetcode.com/problems/minimize-xor/description/

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        // couting bits n both numbers and taking its difference in count
        int n1 = __builtin_popcount(num1);
        int n2 = __builtin_popcount(num2);
        int count = (n1 - n2);

        // since we have to make ans ^ num1 minimum so set ans initially to num1
        int ans = num1;
        
        // if count > 0 means bits in ans are more than num2
        // we need to make its set bits equal to num2 
        // so remove the set bits from right hand side to get min xor of ans and num1
        // run loop till count reach 0
        if (count > 0) {
            while (count--)
                ans = ans & (ans - 1);
        }
        // if count < 0 means we have to inc no. of set bits
        // inc bits from right hand side to get min xor of ans and num1
        // run loop till count reach 0
        else if (count < 0) {
            while (count++)
                ans = ans | (ans + 1);
        }
        return ans;
    }
};



