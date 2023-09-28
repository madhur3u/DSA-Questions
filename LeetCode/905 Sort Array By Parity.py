class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:

        # 2 pointers approach odd pointer should always be at a odd number
        # if not we swap it with even pointer value and increase both pointers
        # in thge end we will have all even values in start and odd at end of the array
        odd, even = 0, 0
        n = len(nums)
        
        while (odd < n):
            if nums[odd]%2 == 1: odd+=1    # inc odd pointer if value already odd
            else:                          # even value found  
                nums[odd], nums[even] = nums[even], nums[odd]    # swap 
                odd+=1                                           # increase both pointers 
                even+=1
        
        return nums    # in place no O1 memory N time
