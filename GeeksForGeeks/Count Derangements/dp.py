# https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/
# https://practice.geeksforgeeks.org/problems/dearrangement-of-balls0918/1#
# % 1000000007 for bigg ans

def countDer(n):
     
    # Create an array to store
    # counts for subproblems
    der = [0]*(n + 1)
     
    # Base cases
    der[1] = 0
    der[2] = 1
     
    # Fill der[0..n] in bottom up manner
    # using above recursive formula
    for i in range(3, n + 1):
        der[i] = (i - 1) * (der[i - 1] % 1000000007 + der[i - 2] % 1000000007) % 1000000007
         
    # Return result for n
    print(*der)
    return der[n] % 1000000007
 
# main
n = 5
print("Count of Derangements is ", countDer(n))

''' 
We can observe that recursion implementation does repeat work. 
For example, see recursion tree for countDer(5), countDer(3) is being evaluated twice.

RECURSION TREE FOR N = 5
                    cdr(5)   
                 /         \     
             cdr(4)          cdr(3)   
           /      \         /     \
       cdr(3)     cdr(2)  cdr(2)   cdr(1)
       /    \
    cdr(2)   cdr(1)	   
'''
