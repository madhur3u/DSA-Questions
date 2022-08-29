# https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1#
# https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n-set-2/

# You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

# Example 1:

# Input: N = 4
# Output: 5
# Explanation:
# For numbers from 1 to 4.
# For 1: 0 0 1 = 1 set bits
# For 2: 0 1 0 = 1 set bits
# For 3: 0 1 1 = 2 set bits
# For 4: 1 0 0 = 1 set bits
# Therefore, the total set bits is 5.


def countSetBits(n):
    # code here
    # return the count
    ans = 0
    x = 1

    while x <= n:
        x = x * 2
        m = (n + 1) // x
        r = (n + 1) % x
        total = m * (x // 2)

        if r > x // 2:
            total = total + (r - x // 2)

        ans = ans + total

    return ans

# main
print(countSetBits(29))
