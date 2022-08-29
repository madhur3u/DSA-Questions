# https://www.geeksforgeeks.org/sieve-of-eratosthenes/  SEE THE EXPLANATION HERE

# this fn provides list of all prime numbers from 1 till N using sieve Of Eratosthenes
# O(N.log(logN))

# Let us take an example when n = 50. So we need to print all prime numbers smaller than or equal to 50.
# We create a list of all numbers from 2 to 50.
# According to the algorithm we will mark all the numbers which are divisible by 2 and are greater than
# or equal to the square of it.
# Now we move to our next unmarked number 3 and mark all the numbers which are multiples of 3
# and are greater than or equal to the square of it.
# We move to our next unmarked number 5 and mark all multiples of 5 and are greater than or equal to the square of it.
# We continue this process So the prime numbers are the unmarked ones: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47.

def primeList(n):

    # Create a boolean array
    # "prime[0..n]" and initialize
    #  all entries it as true.
    # A value in prime[i] will
    # finally be false if i is
    # Not a prime, else true.
    isPrime = [True]*(n+1)
    isPrime[0] = isPrime[1] = 0 # 0 and 1 are not prime numbers

    p = 2 # start from 2 

    # we go till sqrt n, as every non prime after sqrt(n) till n will be set false as we set false every multiple of a prime number
    while p*p <= n:

        # if a number is prime (starting value 2) then go from its square till n and set each multiple as false
        if isPrime[p] == True:

            for i in range(p*p, n + 1, p):
                isPrime[i] = False

        p += 1 # inc p

    ans = []
    for num in range(2, n + 1):
        if isPrime[num]:		# all index still having true in array are prime
            ans.append(num)

    return ans # list of prime till n


# main
print(*primeList(50))

