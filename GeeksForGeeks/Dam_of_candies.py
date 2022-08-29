# https://practice.geeksforgeeks.org/problems/10471201e923a0b88a0c1482e6c7e8cc6fdfe93a/1#

# https://www.geeksforgeeks.org/maximum-water-that-can-be-stored-between-two-buildings/

# Geek wants to make a special space for candies on his bookshelf. Currently, it has N books of different heights, represented by the array height[] and unit width.
# Help him select 2 books such that he can store maximum candies between them by removing all the other books from between the selected books. The task is 
# to find out the area between two books that can hold the maximum candies without changing the original position of selected books. 


def maxCandy(self, a, n):               # a is the array of books
        # Your code goes here
        area = 0
        low = 0
        high = n - 1
        
        while low <= high:
            
            area = max(area, min(a[low],a[high])*(high-low-1))
            
            if a[low] < a[high] : low += 1
            else : high -= 1
        
        return area
      
# logic to is first take two pointers low and high at extreme pos of array now we need to find area b/w these books which will be distance between them
# which will be (high-low-1) multiply it by min height of book at low and high min(a[low],a[high]) and store it in area if it is maximum

# now we change value of low and high depending upon which book height is big change pos of that pointer which has a book of small height 
