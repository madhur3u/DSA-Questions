class Solution {
public:
    int jump(vector<int>& nums) {

        // we maintain the last jumped pos and farthest pos we can reach from any index
        int jumps = 0;
        int last_jump_pos = 0;
        int farthest_pos = 0;

        // iterate in array
        for (int i = 0; i < nums.size() - 1; i++) {

            // the fruthest jump pos from curr index will be nums[i] + i
            // adn till now the furthest we can jump will be max of all nums[i] + [i] till now
            // so we maintain max of nums[i] + i in farthest position
            farthest_pos = max(farthest_pos, nums[i] + i);

            // now we update our last jump pos and jumps when we are at index where we made our last jump
            // initially it will be at 0 so we have 1st jump and last jump pos will be the current farthest jump
            // when next time we reach this if cond, we update the last jump pos to again the max farthest we have found till i so we maintain minimum jumps
            if (i == last_jump_pos) {
                jumps++;
                last_jump_pos = farthest_pos;
            }
        }
        return jumps;
    }
};
