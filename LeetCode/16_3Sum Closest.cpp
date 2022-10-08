class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        // sort the array and store any combination in result
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[n - 1];

        // we take first number through for loop
        // and 2 3 num using 2 pointers left and right
        // just like 3sum
        for (int i = 0; i < nums.size() - 2; i++){

            // initial two pointers for left and right
            int l = i + 1;
            int r = n - 1;

            // loop till l r cross or at same point
            while (l < r){
                
                // compute current 3sum
                int current_sum = nums[i] + nums[l] + nums[r];

                // update pointer acc to the target since array is sorted
                // if sum == target so return that 
                if (current_sum > target) r--;
                else if (current_sum < target) l++;
                else return target;

                // check if current sum is more near than previous result
                // if it is than update result
                if (abs(current_sum - target) < abs(result - target))
                    result = current_sum;
            }
        }
        return result;
    }
};
