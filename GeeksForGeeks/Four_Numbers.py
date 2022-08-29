# https://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/
# https://practice.geeksforgeeks.org/problems/four-elements2452/1#

# Following are the detailed steps. 
# 1) Sort the input array. 
# 2) Fix the first element as A[i] where i is from 0 to n–3. After fixing the first element of quadruple, 
# fix the second element as A[j] where j varies from i+1 to n-2. Find remaining two elements in O(n) time

def find4Numbers(a, n, x):
    
    # Sort the array in increasing order,
    a.sort()

    # Now fix the first 2 elements one by
    # one and find the other two elements
    for i in range(n - 3):
        for j in range(i + 1, n - 2):

            # Initialize two variables as indexes
            # of the first and last elements in
            # the remaining elements
            lo = j + 1
            hi = n - 1

            # now loop till both pass each other
            # since array is sorted so if a[i] + a[j] + a[lo] + a[hi] < x it means that
            # we need to take a higher value of lo hence lo increase and if it is > then
            # need to take lower value of hi index  
            while lo < hi :

                if a[i] + a[j] + a[lo] + a[hi] == x :
                    return True
                elif a[i] + a[j] + a[lo] + a[hi] < x :
                    lo+=1
                else :
                    hi-=1

    return False
    

# main
N = 6
A = [1, 5, 1, 0, 6, 0]
X = 7

print(find4Numbers(A, N, X))
