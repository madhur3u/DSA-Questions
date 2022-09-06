// https://leetcode.com/problems/majority-element-ii/
// Extended Boyer-Moore Majority Vote Algorithm

/*
if we see mathematically there can only be max 2 elements in a n sized array whose freq is more than n/3
so max el we can have is 2 and min is 0 since there is no guarantee there will be a maj el

so we take 2 el and thier 2 counts and use Boyer-Moore Majority Vote Algorithm (refer 169)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // two elements el1 and el2 will hold the potential majority element
        // and thier count in count1 nad count2
        int el1, el2;
        int count1 = 0, count2 = 0;
        
        // iterate in array
        for (int i : nums){
            
            // if we find el1 or el2 again we inc count
            if (el1 == i) count1++;
            else if (el2 == i) count2++;
            
            // this will be executed first so we assign el1 with 1st element
            // and its count will be set to 1
            else if (count1 == 0) {
                el1 = i;
                count1++;
            }
            
            // if we find a diff element from el1 we will assign el2 with that
            // and its count 1
            else if (count2 == 0) {
                el2 = i;
                count2++;
            }
            
            // if none of el1 or el2 present and count > 1 of both
            // we decrease count and if count become 0 of any element
            // in next iteration it will be assigned the next value whatever i will be
            else {
                count1--;
                count2--;
            }
        }
        
        // since we are not sure if el1, el2 will be maj el
        // we will check by counting how many no. of times they occur in array
        count1 = 0, count2 = 0;
        
        for (int i : nums){
            if (el1 == i) count1++;
            else if (el2 == i) count2++;
        }
        
        // this will have list of maj el
        vector<int> ans;
        
        // check if els are maj el if yes push in ans
        if (count1 > nums.size() / 3) ans.push_back(el1);
        if (count2 > nums.size() / 3) ans.push_back(el2);
        
        return ans;
    }
};
