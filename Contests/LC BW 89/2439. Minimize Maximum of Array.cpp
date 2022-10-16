class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {

        // sum have prefix sum add current element to it to get current sum
        // res will hold max formed 
        long long sum = 0, res = 0;

        // iterate in array
        for (int i = 0; i < nums.size(); i++) {

            // compute sum, prev sum value has the prefix sum till i - 1
            sum += nums[i];

            // compute max for current window (0 to i) and compare with prev res to getmax
            long long maximum = ceil(sum / (double)(i + 1));
            res = max(res, maximum); 
        }
        return res;
    }
};

/*
if we need to find the maximum we can have in 2 no. ex in [3 7]
we can divide sum by n = 2 and find ceil --> 10 / 2 --> 5 
so we can reach 5 by doinf the desired operations
3 7
4 6
5 5 we can confirm it by dry run

now when we increase the numbers
[3 7 8 9]

just take all numbers and divide by length -> (3 + 7 + 8 + 9) / 4 --> 27 / 4 --> 7 (ceil)

now this is good if no. are in inc order / sorted array

for unsoreted array ex. [3 7 1 6] or [10 5 1]
we check foe each combination and take the maximum value
[3] -> 3
[3 7] -> 5
[3 7 1] -> 4
[3 7 1 6] -> 5 so 5 is the ans

[10] -> 10
[10 5] -> 8
[10 5 1] -> 6 so max is 10

since when no. are in dec order we cannot decrease the previous number we can only increase it
*/
