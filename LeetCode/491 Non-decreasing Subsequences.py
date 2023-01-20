# https://leetcode.com/problems/non-decreasing-subsequences/description/

# this can be done with brute force backtracking
# we need to try all subsequeneces and check if it meets our criteria
# make dfs callwith 0th index and empty subseq list []
# now in dfs fn we check if size > 1, add if yes
# base case to return when we reach out of nums array
# after that we either need to pick or not pick
# if empty subseq or next nums[i] follow desired order we pick it
# else just inc index and no change in subseq

class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:

        res = set()
        def dfs(i, subseq):

            if len(subseq) > 1: res.add(tuple(subseq))      # condition to add subseq
            if i == len(nums): return                       # base case, out of nums

            # pick
            if not subseq or subseq[-1] <= nums[i]: 
                subseq.append(nums[i])
                dfs(i + 1, subseq)
                subseq.pop()
            
            # not pick
            dfs(i + 1, subseq)
        
        dfs(0, [])
        return res
