# https://www.geeksforgeeks.org/chocolate-distribution-problem/

# Given an array of n integers where each value represents the number of chocolates in a packet. 
# Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

#     Each student gets one packet.
#     The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.

# approach --> sort the array, lets suppose if 3 students --> so if we give them all combination in sorted array
# the diff b/w max and min will be a[i + (3-1)] - a[i] as array is sorted --> so we need to find min of all diffrences 
# min_diff = min(min_diff, a[i + (m-1)] - a[i])


class Solution:

    def findMinDiff(self, a, n, m):

        a.sort()                # sort array
        min_diff = max(a)       # initialize min diff
        
        for i in range(n - m + 1):
          
            min_diff = min(min_diff, a[i + (m-1)] - a[i])   # finding min diff
        
        return min_diff
