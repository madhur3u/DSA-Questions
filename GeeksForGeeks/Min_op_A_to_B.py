# https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1
# https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation

# Given two Arrays A[] and B[] of length N and M respectively. 
# Find the minimum number of insertions and deletions on the array A[], 
# required to make both the arrays identical.
# Note: Array B[] is sorted and all its elements are distinct

# 1. make a array of elements in A which are also present in B --> temp
# 2. now find the length of longest inc subsequence of temp --> len(sub)
# 3. InsDel --> (n - len(temp)) + (len(temp) - maxLen) + (m - maxLen) --> n + m - 2 * maxLen --> this is the ans   

# func to perform binary search
# return the index if value found
# return low if valve not found
def binarySearch(sub, val):
    lo = 0
    hi = len(sub)-1
    while(lo <= hi):
        mid = lo + (hi - lo)//2
        if sub[mid] < val:
            lo = mid + 1
        elif val < sub[mid]:
            hi = mid - 1
        else:
            return mid
    # return low if not found
    return lo

# this function finds longest increasing subsequence using binary search and return length of that (O(nlogn) time)
def LIS(arr):

    # if array has nothing then longest inc subseq len will be zero
    if len(arr) == 0:
        return 0

    sub = [] # this will contain the longest inreasing subsequence

    # iterating in whole arr
    # we first check if the value is already in sub using binary search
    # if pos == len(sub) means value not found and the value is greater than all values in sub as we return low when not found
    # THIS NEEDS TO BE DRY RUN FOR UNDERSTANDING
    for val in arr:

        pos = binarySearch(sub, val)    # finding index 

        if pos == len(sub):             # if this is case means val is > all values in sub as we return low when val not found
            sub.append(val)             # so we append it to end of our sub array to make inc subsequence
        
        else:                           # if we find val or val is between the elements of sub but not in sub 
            sub[pos] = val              # in either case we will have pos < len(sub) --> and we change it to val
    
    return len(sub)                     # len of sub will be max len of inc subsequence

# this will give us minimum insertions and deletions require to make a == b
def minInsAndDel(a, b, n, m):

    # Find LCS using LIS
    # first we find how many elements of b are present in a and save it in temp array
    # converting b to set for better time

    temp = []           # contains the common elements from both arr1 and arr2
    s = set(b)
    for val in a:
        if val in s:
            temp.append(val)

    # now we need to find the longest increasing subsequence from temp
    # since B is sorted so we need to find long inc subset length and (n + m - 2 * maxLen) for result
    maxLen = LIS(temp)
    return (n + m - 2 * maxLen)

# main
a = [1, 2, 5, 3, 1]
b = [1, 3, 5]

print(minInsAndDel(a, b, 5, 3))
