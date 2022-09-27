// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
/*
the idea is to connect the smallest two ropes first and then for the remaining ropes.
We put the smallest ropes down the tree so that they can be repeated multiple times rather than the longer ropes. 
We can achieve this by using the min-heap priority_queue.

Steps:-

    Create a min-heap priority_queue and insert all lengths into the priority_queue.
    Do the following while the size of priority_queue is greater than one. 
    Extract the minimum and second minimum from priority_queue which is present at the top of priority_queue.
    Add the above two extracted values and insert the added value to the min-heap.
    Maintain a variable answer for total cost and keep incrementing it by the sum of extracted values.
    Return the value of the answer at the end.
*/

class Solution {
    public:
    long long minCost(long long arr[], long long n) {
        
        // min heap with all arr elements
        priority_queue <long long, vector<long long>, greater<long long>> pq(arr, arr + n);
        long long ans = 0;
        
        //run till pq size > 1
        while (pq.size() != 1){
            
            // extract the min two elements using top and pop them
            long long x = pq.top();
            pq.pop();
            long long y = pq.top(); 
            pq.pop();
            
            // add the sum to ans, and x+y again to min heap
            ans += (x + y);
            pq.push(x + y);
        }
        return ans;
    }
};
