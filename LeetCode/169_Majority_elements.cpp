// https://leetcode.com/problems/majority-element/
// https://www.youtube.com/watch?v=7pnhv842keE

/*
Approach: 

    Initialize 2 variables: 
        Count –  for tracking the count of element
        Element – for which element we are counting
    Traverse through nums array.
        If Count is 0 then initialize the current traversing integer of array as Element 
        If the traversing integer of array and Element are same increase Count by 1
        If they are different decrease Count by 1
    The integer present in Element is the result we are expecting 
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // two variables which will store result and count of element
        int res = 0;
        int count = 0;
        
        for (int i: nums){
            
            // if count = 0 put the current element in result 
            // and inc the count for it
            if (count == 0){
                res = i;
                count++;
            }
            
            // if count is more than 1 and we found same element in count
            // and if we find some diff el dec the count
            else if (count > 0 && i == res) count++;
            else if (count > 0 && i != res) count--;
        }
        
        // since the question guarantee that we will have a majority el
        // so our res will always contain the majority element aa count for that will be > n/2
        return res;
    }
};
