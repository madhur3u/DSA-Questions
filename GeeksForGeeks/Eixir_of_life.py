# https://practice.geeksforgeeks.org/problems/20290dc4188d384ae1f17d6a14bd2c95ea7012a8/1#

# what we need to find is
# 1. check if it has same prefix and suffix eg in abaabaab -> ab is the same in front and end
#    in aaaa ->  a will be same suffux prefix, in abbabc -> we can never have same pre suf
# 2. checking prefix by slicing list and no. of elements decided by i
# 3. if at any point we find same suffix and prefix, we need to find how many time that substring occur in string
# 4. Corner Case : when len(s) = 1 , we are returning 1 in end, also when no same pre suf it returns 1 in end
# 5. why loop till half ? because prefix and suffix will be same only till half
#    in aaaa we can have aaa also as pr suf but, a will be taken as count of 'a' in string is more than 'aaa'
#    thats why we taking loop half, and substring count from 1 to n/2

def maxFrequency(s):

    i = 1
    # this take care of substring length inc i in each iteration
    # loop till half
    while i < len(s)//2 + 1:		

        s1 = s[: i]				# prefix
        s2 = s[len(s) - i:]			# suffix
        i += 1						

        print(s1, s2)
        
        # checking suffix and prefix
        # if equal then return count of substring
        if s1 == s2: 				
            return s.count(s1)		
    
    # if no substring equal or length 1 -> it returns 1
    return 1						


# main
s = 'ccccccb'
s1 = 'ababaaaab'
s2 = 'a'
s3 = 'aaaa'
s4 = 'abcdef'

print(maxFrequency(s))
print(maxFrequency(s1))
print(maxFrequency(s2))
print(maxFrequency(s3))
print(maxFrequency(s4))
