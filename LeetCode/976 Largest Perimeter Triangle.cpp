/*
for any a b c where a <= b <= c
a b c can form a triangle if a + b > c

so we sort the array and try frming all combnation from end of sorted array till start
this way if we had a valid triangle its perimeter will be largest so we return it
if we never found a vaild triangle we will return 0
*/
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        // sort array
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 3; i >= 0; i--) {
            
            // taking out 3 consecutive num from array for a b c checking for valid triangle
            int a = nums[i], b = nums[i+1], c = nums[i+2];
            if (a + b > c) 
                return a + b + c;
        }
        return 0;
    }
};
