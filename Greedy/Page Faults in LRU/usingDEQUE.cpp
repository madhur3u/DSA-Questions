// https://www.geeksforgeeks.org/program-for-least-recently-used-lru-page-replacement-algorithm/
// https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1
// O(c)*O(n)

class Solution{
public:
    int pageFaults(int n, int capacity, int pages[]) {
     
        // we put the pages in a deque  
        deque<int> dq;
        int ans = 0; // page faults counter
        
        // iterate in pages array
        for (int i = 0; i < n; i++) {
            
            // extract the current page
            int page = pages[i];
            // make iterate which will help in checking if element present in dq already, O(capacity)
            auto itr = find(dq.begin(), dq.end(), page);
            
            // if page not present
            if (itr == dq.end()) {
                
                // if capacity full pop the front element
                if (dq.size() == capacity) dq.pop_front();
                
                // push the page in back, inc page faults count as new page added
                dq.push_back(page);
                ans++;
            }
            // if page already present
            else {
                // delete from whereever it is present O(capacity)
                dq.erase(itr);
                // insert page in back
                dq.push_back(page);
            }
        }
        return ans;
    }
};
