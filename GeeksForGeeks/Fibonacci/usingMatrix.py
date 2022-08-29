# https://medium.com/codebrace/starred-problem-2-nth-fibonacci-number-in-log-n-time-821ea9a18296

# https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/ 
# https://practice.geeksforgeeks.org/problems/cows-of-fooland5818/1#

# this fn calculate fibo using matrix approach in logN time
# % 10*9 + 7 for bigger numbers
def fib(n):
     
    F = [[1, 1],
         [1, 0]]
    
    if (n == 0):
        return 0
      
    power(F, n)
         
    return F[0][1]

# program to multiply two 2*2 matrix
# we make 4 temp variables x-z and store value of multiplication in it
# then we asgn the temp to original matrix as we store ans in original
def multiply22(mat1, mat2):
     
    x = (mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0])
    y = (mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1])
    z = (mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0])
    w = (mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1])
     
    mat1[0][0] = x % 1000000007 
    mat1[0][1] = y % 1000000007
    mat1[1][0] = z % 1000000007
    mat1[1][1] = w % 1000000007
         
# since we need to raise matrix to power n so we use recursion to raise power
# we do this in logn time, by using f**n = f**n//2 * f**n//2 --> and sp case for even
# https://github.com/madhur3u/JAVA/blob/main/Recursion/Power%20x**n/power_log.java  --> power log   
def power(F, n):
    
    # base cases
    if(n == 0 or n == 1):
        return;

    # m is the value to be multiplied in case of odd n//2
    M = [[1, 1],
         [1, 0]]
    
    # using recursion half power in each case
    power(F, n // 2)
    # now we need to multiply the matrices so made a seprate func for matrix mult of 2x2
    multiply22(F, F)

    # for odd power multiply by M using function     
    if (n % 2 == 1):
        multiply22(F, M)
     
# Main Code
if __name__ == "__main__":
    n = 9
    print(fib(n))
