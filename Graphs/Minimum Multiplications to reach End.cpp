/*
https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
we can simply simulate a graph
start multiply by all elements of array will give us new node
then we multiply each node again with all arr element and so on till we reach end
we can reach dijkstra to find the minimum steps -> shortest path from start to end
*/
// shortcuts
typedef pair<int, int> pii;
int MOD = 100000;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {

        // since steps inc by one only so no need of pq
        queue<pair<int, int>> q;
        q.push({start, 0});             // {number, steps}
        vector<int> dist(100000, 1e9);  // since we do mod 10**5, so no. of nodes will be 10**5 only 
        dist[start] = 0;                // no. of steps to reach start will be 0
        
        // dij bfs straversal
        while (!q.empty()) {
                
            int node = q.front().first;         // extract q front and pop
            int steps = q.front().second;     
            q.pop();
                
            // itertae in the numbers array we will multiply with node
            for(auto& itr : arr) {
                
                int num = (node * itr) % MOD;           // get the new number by multiplying with itr
                if (num == end) return steps + 1;       // if this nu is end, return steps + 1
                
                if (dist[num] > steps + 1) {            // if we reached num in lesser steps than prev
                    dist[num] = steps + 1;              // update distance array
                    q.push({num, steps + 1});           // ad the pair in queue
                }
            }
        }
        return -1;  // if we never found end
    }
};
