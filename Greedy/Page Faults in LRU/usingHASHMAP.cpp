// https://www.geeksforgeeks.org/program-for-least-recently-used-lru-page-replacement-algorithm/
// https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1

class Solution{
public:
    int pageFaults(int n, int capacity, int pages[]) {
        
        // set to check for all elements in LRU cache
        // map will have the indexes of all elements so LRU can be found
        unordered_set <int> s;
        unordered_map <int, int> mp;
        int ans = 0; // page faults
        
        // iterate in array
        for (int i = 0; i < n; i++) {
            
            // when capacity is not full 
            if (s.size() < capacity) {
                // check if element does not exist
                // inc page faults count as new page inserted, insert page in set
                if (s.find(pages[i]) == s.end()) {
                    ans++;
                    s.insert(pages[i]);    
                } 
                // we insert index of page irespective of it was already present or not
                // if already present its index will update to a higher index 
                mp[pages[i]] = i;  
            }
            // when maximum capacity reached
            else {
                // when element does not exist, we pop the LRU, we can find LRU by traversing in set
                // finding the minimum index from all elements present in set and pop the element with min index
                if (s.find(pages[i]) == s.end()) {
                    
                    // LRU hold the min index and val the page value to be removed from set
                    int LRU = INT_MAX, val = 0;
                    
                    // iterate in set, find min index and update its value in val
                    for (auto it = s.begin(); it != s.end(); it++) {
                        if (mp[*it] < LRU) {
                            LRU = mp[*it];
                            val = *it;
                        }
                    }
                    // erase LRU insert new page inc page fault
                    s.erase(val);
                    s.insert(pages[i]);
                    ans++;
                }   
                // if element exist we just update new index for that element
                // or even if new el inserted insert new element in map with index
                mp[pages[i]] = i; 
            }
        }
        return ans;
    }
};
