// https://leetcode.com/problems/palindrome-partitioning
// https://leetcode.com/problems/palindrome-partitioning/discuss/1667647/Well-Explained-JAVA-C%2B%2B-PYTHON-JavaScript-oror-Easy-for-mind-to-Accept-it
/*
In the backtracking algorithm, we recursively traverse over the string in depth-first search fashion. 
For each recursive call, the beginning index of the string is given as start.

    Iteratively generate all possible substrings beginning at start index. 
    The end index increments from start till the end of the string.

    For each of the substring generated, check if it is a palindrome.

    If the substring is a palindrome, the substring is a potential candidate. 
    Add substring to the currentList and perform a depth-first search on the remaining substring. 
    If current substring ends at index end, end+1 becomes the start index for the next recursive call.

    Backtrack if start index is greater than or equal to the string length and add the currentList to the result.

end == i;

Time  Complexity: O(N * (2 ^ N))
Space Complexity: O(N * (2 ^ N))
*/

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        
        vector<string> part;
        palindrome_part(s, 0, part, s.size());
        return res;
    }
    void palindrome_part(string s, int idx, vector<string> &part, int n){
        
        // BASE CASE : when whle string is parsed push part to res and return
        if (idx == n){
            res.push_back(part);
            return;
        }
        // traverse from given idx till n and try to find out all palindrome from idx to i
        // if we find a substr from idx to i, we make a partition by sending i + 1 for next fn call
        // a a b , idx = 0
        // at 0, a | a b --> idx = 0, i = 0, we found a palindrome 
        // a a | b --> idx = 0, i = 1, palindrome
        // a a b | idx = 0, i = 2 , not palindrome
        for (int i = idx; i < n; i++){
            
            // check palindrome if yes push substring to part, fn call pop
            if (isPalindrome(s, idx, i)){
                part.push_back(s.substr(idx, i - idx + 1));
                palindrome_part(s, i + 1, part, n);
                part.pop_back();
            }
        }
    }
    // to check palindrome
    bool isPalindrome(string s, int l, int r){
        
        while (l < r){
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
};

/*
Approach Explaination :-
A basic summary of diagram, how we are doing it
Take an example, "xxyy".
If we partition over x|xyy so the substring "x" is a palindrome. Where i can have the first partition.

But, if they don't allow to partition over there, then our second partition will be xx|yy. Because this "xx" is a palindrome substring. 
Thus we still left out with yy, so if i do the partion over here xxy|y the answer will be no, 
because if i do the partition over here the substring "xxy" is not a palindrome.

Can i do a partition over here xxyy|. No. Because xxyy is not a palindromic substring. 
So, we can see when we started we can do a partition over here x|xyy OR xx|yy so that is what we do. We try to do partition where ever it is possible

So, in the first case we did a partition over x|xyy where we left out with xyy. So, if i do a partiton like x|x|yy where x it'self a palindrome. 
And we left out with a substring yy
Now can you do a partition over here x|xy|y. No, because this substring xy is not a palindrome
Again can we do a partition over here x|xyy|. No, because this substring xyy is not a palindrome

So, the only partition possible is x|x|yy. And after that we tend to call the recursion for remaining substring

If i try to do a partition over here x|x|y|y so, the substring y in itself is a palindromic substring. After that we left out with remaining y substring.
Now you ask can we do a partition over here x|x|yy|, Yes

Like this way, we do the partition in complete STRING using recursion. And with the help of Backtracking we store our answer.
*/
