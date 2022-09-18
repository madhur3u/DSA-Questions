// https://leetcode.com/problems/trapping-rain-water/
// PLEASE PLEASE DRY RUN

/*
We start with maxLeft = height[0], maxRight = height[n-1], using 2 pointers left point to the next bar on the left side, 
right point to the next bar on the right side.

How to decide to move left or move right?

    If maxLeft <= maxRight, it means the water level is based on the left side (the left bar is smaller) then move left side:
        If height[left] > maxLeft then there is no trap water, we update maxLeft by maxLeft = height[left].
        Else if height[left] < maxLeft then it can trap an amount of water, which is maxLeft - height[left].
        Move left by left += 1
    Else if maxLeft > maxRight, it means the water level is based on the right side (the right bar is smaller) then move right side:
        If height[right] > maxRight then there is no trap water, we update maxRight by maxRight = height[right].
        Else if height[right] < maxRight then it can trap an amount of water, which is maxRight - height[right].
        Move right by right -= 1.


*/
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        // initial max as the corner elements of left and right
        int maxLeft = height[0];
        int maxRight = height[n - 1];
        int res = 0;
        
        // since no water can be stored in boundary so start l and r 1 distance after / before boundary
        int l = 1, r = n - 2;
        
        // run till both pointers cross each other
        while (l <= r){
            
            // case when left boundary is smaller than right
            // means if the current height is smaller than maxLeft we are sure it can store water as right wall is bigger or equal
            // thats what done in else statement
            // if height of this wall greater than max update max
            // inc the left pointer 
            if (maxLeft <= maxRight){
                if (height[l] >= maxLeft) 
                    maxLeft = height[l];
                
                else 
                    res = res + (maxLeft - height[l]);
                l++;
            }
            
            // same for right , right wall store water when height is less than max
            // and since left wall height is bigger so it can definitely store water
            // update max when current height greater
            else {
                if (height[r] >= maxRight) 
                    maxRight = height[r];
                
                else 
                    res = res + (maxRight - height[r]);
                r--;
            }
        }
        return res;
    }
};
