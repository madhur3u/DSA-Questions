// https://www.youtube.com/watch?v=YbY8cVwWAvw
// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
/*
The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. The problem is to 
find shortest distances between every pair of vertices in a given edge weighted directed Graph.

We store the shortest path in a mtrix so we can access each relation easily.

In this algorithm, for every pair (i, j) of the source and destination vertices, we check every possible 
intermediate vertex (k) and take the minimum one. If dist[i][k] + dist[k][j]  < dist[i][j] , 
it mean we can reach i  to j through k which is less than direct i to j path.

Implementation

step 1: for our help, change all -1 cells to infinite.
step 2: run a loop from 0 to less than n, [intermediate vertex]
inside the loop
   step 3: run a loop from 0 to less than n, [source vertex]
   inside the loop
       step 4: run a loop from 0 to less than n, [destination vertex]
       inside the loop
       step 5: if matrix[i][j] is greater than matrix[i][k] + matrix[k][j], update matrix[i][j]  = matrix[i][k] + matrix[k][j].
loop end
loop end
loop end
step 6: change all infinite cells to -1.

TIME - O(N*N*N)
SPACE - O(N*N)
*/
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    
	    int n = matrix.size();
	    
	    // STEP 1
	    for (int i = 0; i < n; i++) 
	    for (int j = 0; j < n; j++) 
	        if (matrix[i][j] == -1) matrix[i][j] = 1e9;
	        
	    // STEP 2 - 5
	    for (int k = 0; k < n; k++)  
	    for (int i = 0; i < n; i++) 
	    for (int j = 0; j < n; j++) 
	        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	    
	    // additional step when we need to find a negetive cycle
	    // if there is a negetive cycle the distance from node to itself 0-0, 1-1 ... will become negetive
	    // so we check for that
	    for (int i = 0; i < n; i++) 
	        if (matrix[i][i] < 0) return;
	    
	    // STEP - 6
	    for (int i = 0; i < n; i++) 
	    for (int j = 0; j < n; j++) 
	        if (matrix[i][j] == 1e9) matrix[i][j] = -1;
	}
};
