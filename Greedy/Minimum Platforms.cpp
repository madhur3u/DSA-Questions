// https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/
// O(n * logn)

class Solution {
    public:
    int findPlatform(int arr[], int dep[], int n) {
    	
    	// sort both arrays
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	// platforms will tell us no. of platforms needed at an instant, ans will have max platforms
    	int platforms = 1, ans = 1;
    	
    	// two pointers, start arrival pointer i = 1 as we have already considered 1 platform in ans
    	int i = 1, j = 0;
    	
    	// till all arrivals are accounted for
    	while (i < n) {
    	    
    	    // if departure is after the train arriving currently means we need one more platform
    	    if (arr[i] <= dep[j]) {
    	        platforms++;
    	        i++;
    	    }
    	    // when departure is before new train arrival, free a platform inc dep pointer
    	    else {
    	        platforms--;
    	        j++;
    	    }
    	    // update ans
    	    ans = max(ans, platforms); 
    	}
    	return ans;
    }
};
