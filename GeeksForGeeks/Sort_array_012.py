# https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#
# https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

# Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
# Input: 
# N = 5
# arr[]= {0 2 1 2 0}
# Output:
# 0 0 1 2 2
# Explanation:
# 0s 1s and 2s are segregated 
# into ascending order.

class Solution:
    def sort012(self,arr,n):          # input array arr, no of elements n
        # code here
        a = [0]*3                     # array to store count of 0,1,2
        for i in arr:               
            a[i] += 1                 # counting 0,1,2 and storing at index of a[]
        
        i = 0
        for _ in range(a[0]):         # according to count of 0,1,2 update original array
            arr[i] = 0
            i+=1
        
        for _ in range(a[1]):
            arr[i] = 1
            i+=1
        
        for _ in range(a[2]):
            arr[i] = 2
            i+=1
