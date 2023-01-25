class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        
        n = len(edges)
        m1 = [-1]*n
        m2 = [-1]*n
        
        # DFS to make a memo array which tell us dist from node1/node2 to every node it is connected to
        # i --> node, dist --> curr dist of node i from starting point (initial i), memo --> dist array 
        def dfs(i, dist, memo):
            # we run the loop till no next node availiable means i != -1 
            # and memo array has -1, means not prev filled, prevention when we have cycle in graph
            while i != -1 and memo[i] == -1:
                memo[i] = dist
                i = edges[i]
                dist += 1
        
        # form both memo array m1 and m2 for node1 and node2
        dfs(node1, 0, m1)
        dfs(node2, 0, m2)
        
        # initialise ans and min dist
        ans = -1
        min_dist = 1e9
        
        # we loop in both memo array, both of same length n
        # first check if both are >= 0 since -1 means either of the node has not visited ith node
        # then we take max of both dist and compare with min_dist to minimise it
        # store node value for the min dist we encounter
        # return ans
        for i in range(n):
            if m1[i] >= 0 and m2[i] >= 0 and max(m1[i], m2[i]) < min_dist:
                min_dist = max(m1[i], m2[i])
                ans = i
        
        return ans
