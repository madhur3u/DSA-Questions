# https://www.geeksforgeeks.org/count-triplets-with-sum-smaller-that-a-given-value/

def countTriplets(a, n, s):

    # sort the array 1st and initialize count answer as 0
    a.sort()
    ans = 0
    print(a)

    # i will be 1st value of triplet so it will go from 0 -> n - 2 index
    for i in range(n - 2):
        
        # corner elements index initialized after i
        lo = i + 1
        hi = n - 1

        # till indexes dont pass each other or coincide
        while (lo < hi):

            # take out the sum of current triplet
            curr_tr_sum = a[i] + a[lo] + a[hi]

            # now we check if this sum is >= s
            # if it is we need to decrease high
            if curr_tr_sum >= s:
                hi = hi -1
            
            # if sum < s
            else:
                # if sum is less than s means a triplet can be formed here
                # since array is sorted so if a valid triplet can be formed using current lo and hi
                # then triplet can also be formed using curent lo and all elements between lo & hi
                # lo , a ,b, c, d, hi  --> (lo, a) (lo, b) (lo, c) (lo, d) (lo, hi) --> these all are valid if triplet forming with hi
                # so we need to consider them in the count so we condier all elements from lo to high if hi forms triplet
                # ans = ans + (hi - lo)
                # and now in next iteration we check for next value of lo, hi remains same 
                ans = ans + (hi - lo) 
                lo = lo + 1
    
    return ans


# main
a = [7, 0, 1, 2, 3, -7, 5, 6, 8, -9, -4, -2]
n = len(a)
s = 1
print(countTriplets(a, n, s))
