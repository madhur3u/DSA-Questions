class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        // sort both 
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // two pointers i and j for 2 arrays
        int i = 0, j = 0;

        // run loop till we have traversed any of the array
        while (i < g.size() && j < s.size()) {

            // if we can give gth cookie to sth child inc i, means move to next child
            // inc j irresepective of 1st loop
            if (s[j] >= g[i]) i++;
            j++;
        }
        // since i will be increaseed when we can give cookie to a child so i will have the ans
        return i;
    }
};
