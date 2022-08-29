# https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1/?difficulty[]=1&page=1&query=difficulty[]1page1
# https://www.geeksforgeeks.org/minimum-operations-required-make-row-column-matrix-equals/

# The approach is simple, let’s assume that maxSum is the maximum sum among all rows and columns. 
# We just need to increment some cells such that the sum of any row or column becomes ‘maxSum’. 

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
# n = 3
# a = [[1,2,3],[4,2,3],[3,2,1]]

row_sum = []
col_sum = [] 
max_sum = 0

# first we will make 2 arrays which will store sum of all rows and col
# and side by side we are also calculating the max sum of among all row cols
for i in range(n):

    Rtemp = 0
    Ctemp = 0
    for j in range(n):
        Rtemp = Rtemp + a[i][j]     # sum of ith row
        Ctemp = Ctemp + a[j][i]     # sum of ith col

    row_sum.append(Rtemp)
    col_sum.append(Ctemp)

    max_sum = max(max_sum, max(Rtemp, Ctemp))   # max sum out of all rows and cols


# now we need to make our matrix such that all row sum and col sums are equal
# so we need to make sum of each row == sum of each col == max_sum
# for that we will find minimum difference from max_sum of row and col sum
# minimum because we do not want any row or col sum to be more than max_sum
# now update a[i][j] by adding min sum
# if we update a[i][j] corresponding row sum and col sum should also be updated
# in the end we will get our beautiful matrix with all row sum and col sum equal
# operations are the no. of increments made so add diff to it to get that
operations = 0

for i in range(n):
    for j in range(n):

        diff = min((max_sum - row_sum[i]), (max_sum - col_sum[j]))      # find min value

        a[i][j] += diff         # update element
        row_sum[i] += diff      # update corresponding row
        col_sum[j] += diff      # update corresponding col

        operations += diff      # update operations

# printing the updated matrix
for i in range(n):
    print(*a[i])

# no. of operations required to make matrix beautiful
print(operations)
