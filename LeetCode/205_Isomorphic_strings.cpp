// https://leetcode.com/problems/isomorphic-strings/submissions/

/*
The idea is that we need to map a char to another one, for example, "egg" and "add", we need to constract the 
mapping 'e' -> 'a' and 'g' -> 'd'. Instead of directly mapping 'e' to 'a', another way is to mark them with 
same value, for example, 'e' -> 1, 'a'-> 1, and 'g' -> 2, 'd' -> 2, this works same.

So we use two arrays here m1 and m2, initialized space is 256 (Since the whole ASCII size is 256, 128 also 
works here). Traverse the character of both s and t on the same position, if their mapping values in m1 and 
m2 are different, means they are not mapping correctly, returen false; else we construct the mapping, since 
m1 and m2 are both initialized as 0, we want to use a new value when i == 0, so i + 1 works here.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // smap, and tmap will have a value > 0 for those value which we find
        // and same pointer value in both s and t will get same value i + 1
        // initially all 0s
        int s_map[256] = {0}, t_map[256] = {0};
        for (int i = 0; i <= s.size(); i++){
            
            // if unequal values means values alreay mapped, so false
            if (s_map[s[i]] != t_map[t[i]]) return false;
            
            // map the values with each other by assigning same value i + 1 to both in both arrays
            s_map[s[i]] = i + 1;
            t_map[t[i]] = i + 1;
        }
        return true;
    }
};
