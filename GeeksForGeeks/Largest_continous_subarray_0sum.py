# https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

# Algorithm:  
#     Move along the input array from the start to the end.
#     For every index, update the value of sum = sum + array[i].
#     Check every index, if the current sum is present in the hash map or not.
#     If present, update the value of max_len to a maximum difference of two indices (current index and index in the hash-map) and max_len.
#     Else, put the value (sum) in the hash map, with the index as a key-value pair.
#     Print the maximum length (max_len).

def maxLen(n, a):

    if sum(a) == 0:                                     # if sum of all element is zero then whole array is the subarray
        return n

    d = {}                                              # making a dictionaray which will store prefix sum as key and index as value
    prefix_sum = 0                                      # prefix sum will be cumulative sum at each index
    max_len = 0                                         

    for i in range(n):                                  

        prefix_sum += a[i]                              # cumulative sum for 0th index value will be a[0] and after that all a[i] add up

        if a[i] == 0 and max_len == 0:                  # if max_len is 0 till now and we found a zero in array, we consider that zero to be the
            max_len = 1                                 # max subarray length for now, hence length = 1

        if prefix_sum == 0:                             # if at any point we get prefix_sum = 0, it means from starting we are getting our subarray 
            max_len = i + 1                             # till the point we found zero, so length is i + 1

        if prefix_sum in d:                             # checking if same prefix sum is seen before, if yes update value of max len as if we 
            max_len = max(max_len, i - d[prefix_sum])   # are getting same value of prefix sum twice that indicate a subarray with zero sum, so 
                                                        # ' i - d[prefix_sum] ' will be length

        else:
            d[prefix_sum] = i                           # storing sum as key and index at which we get that sum as value in dictionary d

    return max_len

# main
n = int(input())
arr = list(map(int, input().split()))

print(maxLen(n, arr))


'''
One thought come our mind is whenever subarray sum is equal to zero , We get one hint →

Let's understand with example                  0    1   2    3   4   5   6   7

Suppose our input array is →                  {15, -2,  2,  -8,  1,  7,  10, 23}
Ok let's write prefix sum of this array →     {15,  13, 15,  7,  8,  15, 25, 48}

You can see index (prefix array) → 0 and 2 element are same and 0 and 5 element are also same . 
This means between these indexes subarray sum ( in original array ) is zero . 

How we can sure that ??? 
If you add something in number and remove also . the number initially and last are same . 
We can use this approach and solve this problem efficiently . 
For search in prefix array → use HashMap .

The sum-index pair will be stored in a hash-map. A Hash map allows insertion and deletion of key-value pair in constant time. 
Therefore, the time complexity remains unaffected. So, if the same value appears twice in the array, it will be guaranteed that 
the particular array will be a zero-sum sub-array. 
'''
