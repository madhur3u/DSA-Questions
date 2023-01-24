class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        vis = {1:0}     # vis map tell us if cell has been visited and the no. of steps it took to reach there
        q = [1]         # queue for bfs
        
        # bfs iteration, treverse from starting
        for cell in q:
            # thes for loop will give us all cells we can go from current cell after throwing a dice
            # 6 possibiity from cell + 1 till cell + 6 (+7 taken as it is not included)
            for i in range(cell + 1, cell + 7):
                
                # coordinates of the next cell for ex if i = 4 and n = 6 --> x = 0, y = 3
                # these coordinates will be of the bottommost row and since x is even we can do normal traversal to reach y
                # so it will be board[~a][b] for even a
                # if i = 9 and n = 6 --> x = 1, y = 2
                # now to reach cell 9 in board we need to traverse row also from reverse so board[~a][~b]
                x = (i - 1) // n
                y = (i - 1) % n
                next_cell = board[~x][y if x % 2 == 0 else ~y]
                
                # if the new cell we reached has a snake or a ladder we go to that cell 
                if next_cell > 0: i = next_cell 
                # if we reach the last cell
                # return the no. of steps we travelled to reach prev cell + 1 for curr cell
                if i == n * n: return vis[cell] + 1
                
                # if current cell was reached for the 1st time 
                # push it in visited map with no. of steps and also in bfs queue
                if i not in vis:
                    vis[i] = vis[cell] + 1
                    q.append(i)
            
        return -1
