# https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

# Python3 program to find n'th number from series using formula
# In this method we directly implement the formula for nth term in the fibonacci series. 
# Fn = {[(√5 + 1)/2] ^ n} / √5 
# fibonacci Number
import math
 
def fibo(n):
    phi = (1 + math.sqrt(5)) / 2
 
    return round(pow(phi, n) / math.sqrt(5))
     
# Driver code   
if __name__ == '__main__':
     
    n = 9
     
    print(fibo(n))
