// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        // we are traversing vertically
        // checking every column 1st el, 2nd el and so on till
        // any one of the element is over, or a diff prefix found
        for (int j = 0; j < strs[0].size() ; j++){
            
            // now we will compare each vertical elements for the current j
            // index start from 1 to compare with i - 1 th row
            for (int i = 1; i < strs.size(); i++){
                
                // if the string has terminated return the current substring
                // or if the two vertical elements are different, the current substring will be from 0 - j
                // j is not included
                if ((strs[i][j] == '\0') || (strs[i - 1][j] != strs[i][j])) 
                    return strs[0].substr(0,j);
            }
        }
        // if we come out of loop means all srtings were same, so return 1st string
        return strs[0];
    }
};
