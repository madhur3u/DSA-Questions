/*
https://practice.geeksforgeeks.org/problems/topological-sort/1

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, 
vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

In topological sorting, we use a temporary stack. We don't print the vertex immediately, we first recursively call topological sorting 
for all its adjacent vertices, then push it to a stack. Finally, print contents of the stack. Note that a vertex is pushed to stack 
only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack. 
*/

class Solution {
	public:
	vector<int> ans;    // this simulates stack and used to return ans
	vector<int> topoSort(int V, vector<int> adj[]) {
	    
	    int vis[V]= {0};                // visited array
	    for (int i = 0; i < V; i++) {   // for all unvisited nodes call dfs
	        if (!vis[i]) {
	            dfs(i, adj, vis);
	        }
	    }
	    // we will have ans in reverse order as stack is used, reverse ans and return
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
	// dfs will push the node iff all of its connected nodes are visited
	// this way we will be sure node will be stored above all of its connected nodes in stack
	// so store node in end, rest dfs is same
	void dfs(int i, vector<int> adj[], int vis[]) {
	    
	    vis[i] = 1;                             // mark node visited
	    for (auto it : adj[i]) {                // iterate in all connected nodes of curr node
	        if (!vis[i]) dfs(it, adj, vis);     // if the connected node not visited then visit using dfs
	    }
	    ans.push_back(i);                       // push node in stack after all its nodes are visited and have been put in stack using thier dfs function
	}
};
