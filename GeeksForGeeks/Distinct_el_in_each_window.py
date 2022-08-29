# https://www.geeksforgeeks.org/count-distinct-elements-in-every-window-of-size-k/

# DEFAULT DICT --> https://www.geeksforgeeks.org/defaultdict-in-python/
# defaultdict do not give key error when key not present, it give it the default value provided in arguments as function

from collections import defaultdict

def countDistinct(a, n, k):

    d = []

    # m = defaultdict(lambda:0)     # passed a fn (lambda) so if key not prsent value of key will be taken 0
    m = defaultdict(int)            # same can be done just using int in args    
    dist_count = 0                  # this will hold value of distint count in each iteration of window

    # for 1st window
    for i in range(k):
        if m[a[i]] == 0:            # if a[i] is not present / a[i] do not have any count (if a[i] has a count, means it already occured)
            dist_count += 1         # we add 1 to count
        m[a[i]] += 1                # since we need to consider a[i] so inc the count of value by 1
    
    d.append(dist_count)

    # for all other windows
    # 1st remove 1st element of previous window then add next element

    for i in range(k, n):

        # Remove first element of previous window
        # If there was only one occurrence,
        # then reduce distinct count
        if m[a[i - k]] == 1:                    # if 1st element of prev window occured only 1 time
            dist_count -= 1                     # we decrease count as that is not considered in new window
        m[a[i - k]] -= 1                        # reduce the count of 1st element of prev window (it will be >= 1)

        # Add new element of current window
        # If this element appears first time,
        # increment distinct element count   
        if m[a[i]] == 0:                # if a[i] is not present / a[i] do not have any count (if a[i] has a count, means it already occured)
            dist_count += 1
        m[a[i]] += 1    


        d.append(dist_count) 
    
    print(d)



# main
n = [1,1,1,1,2,5,8,7,4,6,9,8,1,2,3,4,5,5,6,7,1,2]
print(len(n))
countDistinct(n, len(n) , 6)

'''
using array and set--> TLE

def countDistinct(a, n, k):

    i = 0
    d = []
    sub = a[i:i + k]                # take the 1st window
    d.append(len(set(sub)))         # count distinct el in it
    i = i + k
    while(i < n):
        
        sub[i % k] = a[i]           # now in the sub array, just replace one element with a[i] to make new window
        d.append(len(set(sub)))     # count distinct
        i += 1
    
    print(d)
'''
