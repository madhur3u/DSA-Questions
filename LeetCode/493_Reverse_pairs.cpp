// https://leetcode.com/problems/reverse-pairs/
// FIRST READ MERGE SORT
// THEN COUNT INVERSIONS UNDER ARRAY SECTION

class Solution {
public:
  
    // we need to find all pairs in which a[i] > 2* a[j]
    // for that we will use merge sort to partition array and sort it
    // and whle merging sorted partitions
    // we will check for inversions
    int merge(vector<int> &a,int lo, int mid, int hi){
    
        int i = lo, j = mid + 1;
        vector<int> temp (hi - lo + 1);
        int k = 0;
    
        int inv = 0; 
        
        // below loop will check of all reverse pairs for the current partitions
        // if we found on pair then all elements to the right of a[i] will also form reverse pair with current a[j]
        // therefore we use inv = inv + (mid - i + 1)
        // why we are not doing this while merging is because while areging we check for a[i] > a[j] and required pairs might not be considered
        while (i <= mid && j <= hi){
            if ((long)a[i] > (long)2 * a[j]){
                inv = inv + (mid - i + 1); 
                j++;
            }   
            else 
                i++;       
        }
        
        // NORMAL MERGE SORT ALGO
        i = lo, j = mid + 1;
        
        while (i <= mid && j <= hi){
            if (a[i] > a[j])temp[k++] = a[j++];
            else temp[k++] = a[i++];       
        }
        while (i <= mid) temp[k++] = a[i++];
        while (j <= hi)  temp[k++] = a[j++];
    
        for(i = 0, k = lo; k<=hi; k++){
            a[k] = temp[i++];
        }
        
        // return the no. of reverse pairs found in current merging
        return inv;
    }
    
    int count_inversions(vector<int> &a,int lo, int hi){
    
        int ans = 0;
    
        if (lo < hi){
    
            int mid = lo + (hi - lo)/2;
            ans += count_inversions(a, lo, mid);
            ans += count_inversions(a, mid + 1, hi);
            ans += merge(a, lo, mid, hi);
        } 
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        
        return count_inversions(nums, 0, nums.size() - 1);
    }
};
