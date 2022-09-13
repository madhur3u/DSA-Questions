// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        
        int current_depth = 0;
        int max_depth = 0;
        
        // traverse in string
        for (auto ch : s) {
            
            // inc the current depth when a open bracket found
            // also update max depth if this is the max current depth till now
            if (ch == '(') {
                current_depth++;
                max_depth = max(max_depth, current_depth);
            }
            
            // decrease current depth when bracket close found
            else if (ch == ')') current_depth--; 
        }
        // max depth will hold the max nesting depth
        return max_depth;
    }
};
