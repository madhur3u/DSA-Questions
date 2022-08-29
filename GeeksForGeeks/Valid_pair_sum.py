# https://www.geeksforgeeks.org/number-of-pairs-in-an-array-with-the-sum-greater-than-0/
# need to find all pairs with sum more than zero

class Solution:
    def ValidPair(self, a, n): 
    	# first sort the array
    	a.sort()
    	
      # initialize 2 pointers at start and end
    	lo = 0
    	hi = n - 1
    	
    	ans = 0 # this will hold the count
    	
      # this will run till index pass each other or coincide
    	while (lo < hi):
    	    
          # current sum of the pair
    	    current_sum = a[lo] + a[hi]
    	    
          # if sum is less than zero, since array is sorted so we need to increase low
    	    if current_sum <= 0:
    	        lo += 1
    	    
          # if sum is valid --> we need to consider all pairs from current lo to current hi
          # now decrease hi as all valid pairs with this high is considered
    	    else:
    	        ans += (hi - lo)
    	        hi -= 1
    	 
        return ans
