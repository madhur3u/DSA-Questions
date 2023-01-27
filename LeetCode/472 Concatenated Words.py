class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        
        d = set(words)  # set of all words in list for o(1) searching
        memo = {}       # memo dict
        
        # dfs fn to find if a particuar word is concatenated or not
        def dfs(word):
            # if the word is in memo means already searched return the stored result
            if word in memo: return memo[word]
            # else set the word in memo to be false
            memo[word] = False
            
            # we need to search for each word slice so run loop from 1 till n
            # slice the prefix and suffix at every i
            for i in range(1, len(word)):
                prefix = word[:i]           
                suffix = word[i:]
                
                # if both prefix and suffix in set d set memo to true and break
                if prefix in d and suffix in d:
                    memo[word] = True 
                    break
                # else if prefix found and suffix dfs returns true, means it has more slices and all in d
                # true in memo and break
                elif prefix in d and dfs(suffix):
                    memo[word] = True
                    break
            # return whatever stored in memo
            # if word was there it would have been true else will return false
            return memo[word]
        
        # to store result
        res = []
        # traverse in words list and check for each word store in ans if return true
        for word in words:
            if dfs(word): res.append(word)
        
        return res
