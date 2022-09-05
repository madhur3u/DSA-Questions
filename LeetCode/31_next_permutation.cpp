// https://leetcode.com/problems/next-permutation/
// https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
// https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/

// REFER NOTES PLEASE

class Solution {
public:
    //fn to swap two values
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }  
    // fn to reverse array from low to high index
    void reverse (vector<int> &a, int low, int high){
        
        while (low < high){
            int temp = a[low];
            a[low] = a[high];
            a[high] = temp;
            
            low++;
            high--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        
        // j will hold the value to be swapped to make next permutation
        int j = 0, i;
        
        // traverse array from reverse
        // check for nums[i - 1] < nums[i] and as soon as we find this
        // store i - 1 value in j and break
        // we have found the number which is not in inc order from reverse
        for (i = nums.size() - 1; i >= 1; i--){         
            if (nums[i - 1] < nums[i]) {
                j = i - 1;
                break;
            }
        }
        
        // if i == 0 means it is the last permutation 
        // so reverse the array to get 1st permutation and return
        if (i == 0){
            reverse(nums, 0, nums.size()-1);
            return;
        }
        
        // now we need to swap jth value with the > value in the subarray from j + 1 to end
        // for that traverse the array from end swap when found
        // and reverse the array from j + 1 to end to get next perm nd return
        for (i = nums.size() - 1; i > j; i--){         
            if (nums[i] > nums[j]){
                swap(nums[i], nums[j]);
                reverse(nums, j + 1, nums.size()-1);
                return;
            }
        }
    }
};
