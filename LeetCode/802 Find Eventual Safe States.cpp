class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> outdegree(n, 0), ans;   
        vector<bool> temp(n, 0);

        // r graph will have reverse graph, means opposite links so we can find outdegree
        vector<vector<int>> rGraph(n);
        queue<int> q;
        
        // make reverse graph and outdegree vector
        for (int i = 0; i < n; i++) {

            for (int it : graph[i])
                rGraph[it].push_back(i);
            
            outdegree[i] = graph[i].size();
            if (outdegree[i] == 0) q.push(i);
        }

        // push current q element in temp
        // dec outdegree of all nodes coming to curr node by 1
        // if outdegree reach 0 we push it in q
        while (!q.empty()) {

            int node = q.front(); q.pop();
            temp[node] = 1;
            for (int it : rGraph[node]) {
                outdegree[it]--;
                if (outdegree[it] == 0) q.push(it);
            }
        }

        // from temp vector push all set nodes to ans to get ans in sorted order
        for (int i = 0; i < n; i++) 
            if (temp[i]) ans.push_back(i);
        
        return ans;
    }
};
/*

Approach

    We will use Topological Sort in this problem.
    We will take use queue and store all the nodes with zero outdegree in it.
    The nodes with zero outdegree are our safe nodes. Hence, we include it in our answer.
    We we remove nodes with zero outdegree from graph, all the nodes which we connected to that node, 
    their outdegree also decreases by one.
    In last, if no node with outdegree zero is left, we stop our process.
*/
