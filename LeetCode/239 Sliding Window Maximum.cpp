class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // monotonic ecreasing deque store val in dec order only
        // we will store el in deque for a sliding window, store thier indices
        // for next window delete prev elements if present and add next element if in dec order
        deque<int> dq;
        vector<int> res;

        // iterating in array nums
        for (int i = 0; i < nums.size(); i++) {

            // case when a element from previous sliding window is present in deque
            // since we are storing elements in inc order of index so the lowest index will be in front
            // we check if the front index is out of our left boundary of sliding window
            // and pop that if it is
            if (!dq.empty() && dq.front() == i - k) 
                dq.pop_front();

            // this loop will make the dec monotonic deque 
            // if a greater element is found we pop all smaller elements
            while (!dq.empty() && nums[dq.back()] < nums[i]) 
                dq.pop_back();

            // push the current element in deque
            dq.push_back(i);

            // our 1st window will form from k - 1 th index 
            // and for a window the max value will be at front as dec deque so push in res
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
