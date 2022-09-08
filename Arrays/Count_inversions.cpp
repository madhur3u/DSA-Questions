// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// please read MERGE SORT before this

class Solution{
  public:
    
    // function to merge two sorted array 
    long long int merge(vector<long long> &a,int lo, int mid, int hi){
    
        int i = lo, j = mid + 1;
        vector<long long> temp (hi - lo + 1);
        int k = 0;
        
        // this will hold the inversions
        long long int inv = 0;
    
        while (i <= mid && j <= hi){
            
            // if element in left side is bigger than right side
            // it means inversion but since array is sorted
            // so all elements to right side in left array will also be bigger than a[j]
            // hence all should be counted in inversions so inv += (mid - i + 1), total elements left from current element till end 
            if (a[i] > a[j]){
                temp[k++] = a[j++]; 
                inv = inv + (mid - i + 1); 
            } 
            else temp[k++] = a[i++];       
        }
        while (i <= mid) temp[k++] = a[i++];
        while (j <= hi)  temp[k++] = a[j++];
    
        for(i = 0, k = lo; k<=hi; k++){
            a[k] = temp[i++];
        }
        return inv;
    }
    
    // first function of merge sort
    // recursive function
    long long int count_inversions(vector<long long> &a,int lo, int hi){
        
        // this will hold no. of inversions
        // add all inverions from previous recursive calls 
        // and for current merge in ans
        long long int ans = 0;
    
        if (lo < hi){
    
            int mid = lo + (hi - lo)/2;
            ans += count_inversions(a, lo, mid);
            ans += count_inversions(a, mid + 1, hi);
            ans += merge(a, lo, mid, hi);
        } 
        return ans;
    }
    
    // main function
    long long int inversionCount(long long arr[], long long N)
    {   
        // creating a copy of original array as we do not want to change it 
        vector<long long> temp(arr, arr + N);
        
        // this fn returns total no. of inversions
        // using merge sort technique
        return count_inversions(temp, 0, N-1);
    }

};
