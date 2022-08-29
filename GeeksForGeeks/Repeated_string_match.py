# https://practice.geeksforgeeks.org/problems/0cba668df04d657fde4d1bd28b626a01e61097f1/1#

# https://www.geeksforgeeks.org/minimum-number-of-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it/

# Given two strings A and B, find the minimum number of times A has to be repeated such that B becomes a 
# substring of the repeated A. If B cannot be a substring of A no matter how many times it is repeated, return -1.


def repeatedStringMatch(a, b):
    # code here
    count = 1                     # initailizing count
    s = a                         # this will store the repeated value of a to check if b is substring or not

    if b in a:                    # if b is already a substring we will return 1 as a need to be used only once
        return 1

    while len(b + a) > len(s) :   # len(b + a) to cover all the cases 
       
        s = s + a                 # inc value of s by adding a
        count += 1                # inc count as a is now repeated
        if b in s:                # check if b is substring
            return count

    return -1                     # if it come out of loop it means b can never be substring so - 1

# main
a = input()
b = input()
print(repeatedStringMatch(a,b))
