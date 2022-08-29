# https://www.geeksforgeeks.org/maximum-sum-pairs-specific-difference/

# Given an array of integers arr[] and a number K.You can pair two numbers of the array if the difference between 
# them is strictly less than K. The task is to find the maximum possible sum of such disjoint pairs.

# Input  : arr[] = {3, 5, 10, 15, 17, 12, 9}, K = 4
# Output : 62
# Explanation:
# Then disjoint pairs with difference less than K are, (3, 5), (10, 12), (15, 17)  
# So maximum sum which we can get is 3 + 5 + 12 + 10 + 15 + 17 = 62
# Note that an alternate way to form disjoint pairs is, (3, 5), (9, 12), (15, 17), but this pairing produces lesser sum.

def maxSumPairWithDifferenceLessThanK(a, n, k):

    # Sort elements to ensure every i and
    # i-1 is closest possible pair
    a.sort()
    s = 0		# this holds the sum of all disjoint pairs

    # To get maximum possible sum, iterate
    # from largest to smallest, giving larger
    # numbers priority over smaller numbers
    # so we will always get max sum for current k as we traverse from last
    i = n - 1
    while (i > 0):

        # when diff b/w pairs is less than k, that pair will be considered for sum
        # and i -= 2 is done as we dont want to take any element from this pair so i-=2
        # ensure this pair is not touched now
        if a[i] - a[i - 1] < k:
            s += (a[i] + a[i - 1])		# add pair to sum 
            i -= 2					

        # if pair not found -1 to go to next element  
        else:
            i -= 1

    return s

# main
arr = [3, 5, 10, 15, 17, 12, 9]
n = 7
k = 4
print(maxSumPairWithDifferenceLessThanK(arr, n, k))
