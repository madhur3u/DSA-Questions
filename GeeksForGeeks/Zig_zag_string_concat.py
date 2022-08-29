# https://www.geeksforgeeks.org/print-concatenation-of-zig-zag-string-form-in-n-rows/

# Given a string and number of rows ‘n’. Print the string formed by concatenating n rows 
# when the input string is written in row-wise Zig-Zag fashion.

# Input: 
# str = "GEEKSFORGEEKS"
# n = 3
# Output: GSGSEKFREKEOE
# Explanation: 
# Let us write input string in 
# Zig-Zag fashion in 3 rows.
# G       S       G       S
#   E   K   F   R   E   K
#     E       O       E
# Now concatenate the two rows and ignore spaces
# in every row. We get "GSGSEKFREKEOE"

def convert(s, n):

    # corner case for n 1 return same string as no zigzag happen
    if n == 1:
        return s

    # initialize a empty 2d arrays with n rows 
    ans = [[] for i in range(n)]

    # i will tell us the row as we can see that weneed to print in a pattern
    # 0 1 2 1 0 1 2 1 0 1 2 1 0 where 0 1 and 2 are row numbers
    # so we need to puch particular character in row acc to pattern
    # at 0 we need to increse row and at i = n - 1 we need to decrease
    i = 0
    for char in s:

        # append the character in particular row
        ans[i].append(char)

        # if i = 0 we need to inc row so make a variable mod = 1
        if i == 0:
            mod = 1
        
        # if i = n - 1 (2 in example) make mod  = -1
        elif i == n - 1:
            mod = -1

        # change i acc to mod to get pattern 0 1 2 1 0 1 2 1 0 1 2 1 0 
        i += mod

    # now we need to add all rows together
    # first convert 2d array to 1d using sum(ans, []) 
    # then convert to string by joining all together 
    return ''.join(sum(ans, []))


s = 'GEEKSFORGEEKS'
n = 3
print(convert(s, n))
