// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& a) {
        
        // keeping index of both zero and non zero pointer at oth pos
        int zero = 0;
        int no_zero = 0;
        int n = a.size();

        while (no_zero < n){
            
            // if we encounter 0 at non zero pos we increase the pointer
            // doing this as we need to find all non zero and push to front
            // so we will find the non zero and swap with the pointer holding zero
            if (a[no_zero] == 0) no_zero++;
            
            // here we will swap if we do not have zero at non zero pointer
            // if both pointer at same pos no effect
            // zero pointer will always be in zero when a real swap is done
            // inc both pointers
            else{

                int temp = a[zero];
                a[zero] = a[no_zero];
                a[no_zero] = temp;

                zero++;
                no_zero++;
            }
        }
    }
};
