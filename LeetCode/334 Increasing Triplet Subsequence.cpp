/*
we need to find 3 minimums in the sequence if found we return true
here we just find 2 min and if a number is > min1 and 2 then we found our sequence
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        // case when array size less than 3
        if (nums.size() < 3) return false;

        // make 2 variables to store 2 mins inititally set them to max value
        int min1 = INT_MAX, min2 = INT_MAX;

        // iterate in array nums
        for (int x : nums) {

            // update min 1 if num is less than both as min1 < min2 
            // if n > min1 but less than min2 update min2
            // if num >> both means inc subseq found return true
            if      (x <= min1) min1 = x;
            else if (x <= min2) min2 = x;
            else    return true;
        }
        return false;
    }
};

/*
This solution is correct for input [2, 6, 1, 8]. It doesn't matter that c1 is set to the incorrect 
number, you are comparing the 8 to c2. It is greater so you return true. And c2 is only set because you 
found a c1 before it which is smaller. It is not possible for c2 to be set to a certain number and not 
have a number before it be smaller. So you still can find the subsequence, even though {c1, c2, c3} is 
not necessarily the correct subsequence.
*/
