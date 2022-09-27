// https://leetcode.com/problems/push-dominoes/

class Solution {
public:
    string pushDominoes(string d) {
        
        // adding a L and R at extremes wont have any effect
        // this will help us in dealing with edge cases
        d = 'L' + d + 'R';
        string res = "";

        // two pointers, both will be either at L or R
        // then we check whats in right and left and accordingly push to res
        for (int i = 0, j = 1; j < d.size(); j++){
            
            // we need to place i and j at L or R and not '.'
            if (d[j] == '.') continue;
            
            // no. of elements between i and j
            int count_el = j - i - 1;
            
            // insert value at i, not if i == 0 as we have added that ourself
            if (i > 0) res += d[i];
            
            // when equal add any of el at i or j in res, no. of elements to add given by count_el
            if (d[i] == d[j]) 
                res += string(count_el, d[i]);
            
            // when left is L and right R, if any '.' dominoes, they wont be pushed so add '.'
            else if (d[i] == 'L' && d[j] == 'R')
                res += string(count_el, '.');
            
            // case when left is R, right L
            // add half right R elements and half left L elements
            // in case of odd elements b/w L and R, we also add a '.' in middle by string(count_el%2, '.')
            else 
                res += string(count_el/2, 'R') + string(count_el%2, '.') + string(count_el/2, 'L');
            
            // make i = j, to add that in res in next iteration
            // the last R added by us will not be pushed as when i will be at last pos j will be out of range
            i = j;
        }
        return res;
    }
};
