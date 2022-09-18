// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& a) {
        
        // we take a max so far on the left side and move right
        // if we find height equal or greater than maxsofar we make our ans
        // reduce the no. of blocks i.e. heights in between
        int maxsofar = 0, blocks = 0, ans = 0;
        int n = a.size();

        for (int i = 1; i<n; i++){

            if (a[i] >= a[maxsofar]){
                ans = ans + (i - maxsofar - 1)*(min(a[i], a[maxsofar])) - blocks;
                maxsofar = i;
                blocks = 0;
                continue;
            }
            blocks += a[i];
        }

        // do the above again after reversing the array 
        // dont take equal condition here
        reverse(begin(a), end(a));
        maxsofar = 0, blocks = 0;

        for (int i = 1; i<n; i++){

            if (a[i] > a[maxsofar]){
                ans = ans + (i - maxsofar - 1)*(min(a[i], a[maxsofar])) - blocks;
                maxsofar = i;
                blocks = 0;
                continue;
            }
            blocks += a[i];
        }

        return ans;
        }
};
