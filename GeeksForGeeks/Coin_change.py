# https://practice.geeksforgeeks.org/problems/coin-change2448/1#
# https://www.geeksforgeeks.org/coin-change-dp-7/

def update_table(table, N, value):
    for i in range (value, N + 1):
        table[i] = table[i] + table[i - value]

def count_combination(N, S, m):

    # table[i] will be storing the number of solutions for
    # value i. We need n+1 rows as the table is constructed
    # in bottom up manner using the base case (n = 0)
    # Initialize all table values as 0
    table = [0]*(N + 1)                                
    table[0] = 1                                    # Base case (If given value is 0)

    # Pick all coins one by one and update the table[] values
    # after the index greater than or equal to the value of the
    # picked coin
    for value in S :
        update_table(table, N, value)

    return table[N]      

# main
n = 10
m = 4                                               # no. of elements in S
S = [2,5,3,6]                                       # to find ways to get N from elements in S, repitition is allowed
print(count_combination(n, S, m))
