# we try to put dot after each digit in string s 
# then we need to check if the ip is valid or not

class Solution:
    # main
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        self.dfs(s, res, 0, "")
        return res
    
    # dots are the no. of dots we have in ip, when count reach 4 means we might have our answer
    def dfs(self, s, res, dots, ip):

        # case 1 dots are 4 and we have reached end of string 
        # push the ip add formed in res and return
        if dots == 4 and len(s) == 0:
            res.append(ip[:-1])
            return
        # if either of the cond is true we return
        elif dots == 4 or len(s) == 0:
            return
        
        # run loop 3 times as max no. we can have between 2 dots are 3
        # we will check each false condition and form address
        for i in range(3):
            if i + 1 > len(s): break            # false cond 1 : if string is over
            if int(s[:i + 1]) > 255: break      # false cond 2 : if address b/w 2 dots > 255
            if i > 0 and s[0] == '0': break     # false cond 3 : if digit > 1 and 1st value is 0

            # if we are here means current digits can be taken in our ip address
            # so add in ip address with a dot --> ip + s[:i + 1] + '.'
            # also inc dot count by 1
            # we modify the given string, we send substring from the next index till end for further computation
            self.dfs(s[i + 1:], res, dots + 1, ip + s[:i + 1] + '.')
