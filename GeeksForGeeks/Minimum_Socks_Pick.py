# https://practice.geeksforgeeks.org/problems/620fb6456d6515faddd77050dfbf2821d7a94b8a/1#

def find_min(a, n, k):

    # Total number of socks
    total = sum(a)

    # Number of colors having even number of socks
    even = 0
    for val in a:
        even += (1 - val % 2)

    # This formula will work for the "worst" case, i.e.
    # if number of socks a[i] is an odd number for all color
    # first select all socks once --> n
    # now if we add 1 sock we will have a pair so add no. remaining pairs (k - 1)*2
    ans = n + (k - 1)*2 + 1  # or open this and eq become n + 2*k - 1

    # now considering for even cases too
    # The concept is: For the last (even - 1) pairs you
    # only need to pick 1 sock instead of 2.
    last = total - (even - 1)
    diff = ans - last

    if diff > 0:
        ans -= diff // 2

    if ans <= total:
        return ans
    # if not possible when no. of socks needed are greater than no. availiable
    return -1

# main code
print(find_min([3, 4, 5, 3], 4, 6))                 # ans --> 15
print(find_min([9, 9, 7, 8, 6, 7, 6, 7], 8, 26))    # ans --> 58    
