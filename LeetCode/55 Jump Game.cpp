class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();

        // initial target is the last position (index)
        int target = n - 1;

        // iterate from 2nd last pos till 0
        for (int i = n - 2; i >= 0; i--) {
            // if we can reach target from current index, update target to i
            if (nums[i] + i >= target) target = i;
        }
        // check if path found
        return target == 0;
    }
};
/*
Q1: How can I reach to the last index (I will call it last_position) from a preceding index?

    If I have a preceding index idx in nums which has jump count jump which satisfies 
    idx+jump >= last_position, I know that this idx is good enough to be treated as the last index 
    because all I need to do now is to get to that idx. 
    I am going to treat this new idx as a new last_position (target used in above code).

we repeat the above process again, if we find a index from which we can reach target or last index
our question is now reduced to reach that index so we update target to i
if we have a path the target will finally reach 0 we check that in end
*/
