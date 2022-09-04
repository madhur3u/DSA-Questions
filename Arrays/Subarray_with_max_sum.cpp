// print subarray with maximum sum
// https://www.geeksforgeeks.org/print-the-maximum-subarray-sum/
// to find how max subarray sum works refer kadane's algo

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int current_sum = 0;
        int max_sum = INT_MIN;
        
        // we will store our ans indices in these variables
        int low = 0, lowtemp = 0, high = 0;
        
        for (int i = 0; i<nums.size(); i++){
            
            // if curr sum less than zero 
            // we update that index to lowtemp
            // why not low? as it can affect our ans if max subarray found at starting
            if (current_sum < 0){
                current_sum = 0;
                lowtemp = i;
            } 
            
            // update curr sum
            current_sum += nums[i];
            
            // if curr sum greater
            // update max sum and indexes low and high
            // low will be the previous index from which we start subarray at lowtemp
            // high will be the current index at which i is
            if (current_sum > max_sum){
                max_sum = max(max_sum, current_sum);
                low = lowtemp;
                high = i;
            }
        }
        // printing the subarray with max sum
        for (int i = low; i<=high; i++){
            cout<<nums[i]<<" ";
        }
        return max_sum;
        
    }
};
