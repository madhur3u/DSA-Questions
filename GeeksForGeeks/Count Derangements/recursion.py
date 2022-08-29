# https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/

def countDer(n):

    # Base cases
    if (n == 1): return 0
    if (n == 2): return 1

    ans = (n - 1) * (countDer(n - 1) + countDer(n - 2))
    return ans

# main
n = 4
print("Count of Derangements is ", countDer(n))

''' 
for n = 4 --> [1,2,3,4]
1st lets see for 1, we cannot have 1 in 1st pos so we can have it in 3 places --> (n - 1) places
now in recursive approach we llok for next element how it can be arranged

so lets consider 2
case1 --> when 1 is fixed at pos 2 --> so we can arrange 2 in 3 pos -- > f(n - 1) places
case2 --> when 1 is not in 2's pos --> 2 can be fixed in 2 places only as it can never be in 2nd pos --> f(n - 2) places

so above 2 are the ways in which 2 can arrange f(n - 1) + f(n - 2) , and so no we will go till we reach base case

base cases 
    if (n == 1): return 0    --> as 1 element cannot be arranged 
    if (n == 2): return 1    --> as 2 element has only one other way

RECURSION TREE FOR N = 5
                    cdr(5)   
                 /         \     
             cdr(4)          cdr(3)   
           /      \         /     \
       cdr(3)     cdr(2)  cdr(2)   cdr(1)
      /     \
    cdr(2)   cdr(1)	   
'''
