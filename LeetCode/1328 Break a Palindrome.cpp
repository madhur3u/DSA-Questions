class Solution {
public:
    string breakPalindrome(string p) {

        int n = p.size();
        if (n == 1) return "";

        // since palindrome repeat itself after half so we run till half of string
        // if we get any char non a in 1st half we make it 'a' and return to have lex sm str possible
        // in case of all a's if length even or odd
        // aaaa, aaa we can have lex small string as -> aaab and aab so as the for loop end we did that
        // one more case for odd string -> aacaa --> only 1 mid element not a 
        // here also we have to change last char to b as if we make c = a it will be a palindrome
        // since we run till n/2 so loop will not get to that c it will end just before that
        // and ans will be made using p[n - 1] = 'b'; --> aacab
        for (int i = 0; i < n/2; i++) {
            if (p[i] != 'a') {
                p[i] = 'a';
                return p;
            }
        }
        p[n - 1] = 'b';
        return p;
    }
};
