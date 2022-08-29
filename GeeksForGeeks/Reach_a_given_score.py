# https://www.geeksforgeeks.org/count-number-ways-reach-given-score-game/

# The idea is to create a table of size n+1 to store counts of all scores from 0 to n. 
# For every possible move (3, 5 and 10), increment values in table.

# DRY RUN for better understanding

def count_combination(sum):

    table = [0]*(sum + 1)                       # this table will store all the count of solutions till value od sum

    table[0] = 1                                # base case as if sum is zero, ans will be one

    # One by one consider given 3 moves and update the
    # table[] values after the index greater than or equal
    # to the value of the picked move.

    for i in range (3, sum + 1):
        table[i] = table[i] + table[i - 3]
    
    for i in range (5, sum + 1):
        table[i] = table[i] + table[i - 5]

    for i in range (10, sum + 1):
        table[i] = table[i] + table[i - 10]

    return table[sum]                           # the ans will be at the sum index of the table

# main
n = 20
print('Count for', n, 'is', count_combination(n))
n = 13
print('Count for', n, 'is', count_combination(n))
