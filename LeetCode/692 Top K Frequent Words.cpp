/*
The idea is to keep a count of each word in a HashMap and then insert in a Priority Queue.
While inserting in pq, if the count of two words is same then insert based on string compare of the keys.
O(nlogk) time & O(n) space
*/

// custom comparactor to sort pair aoncc to our need
class MyComparator {
public:
    bool operator() (const pair<int, string> &p1, const pair<int, string> &p2) {

        // if first el of pair equal we want smaller string to be in front
        if (p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // add all elements with thier freq in map
        unordered_map <string, int> mp;
        for (auto word : words) mp[word]++;

        // make pq acc to our comparator
        // this will be a minheap in which if freq is same 2nd will be arranged in lex order
        // if we use min heap directly it will be opposite
        // iterate in map and push freq, word pair
        priority_queue <pair<int, string>, vector<pair<int, string>>, MyComparator> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});

            // we only store Top K Freqency word we have met so far in our min heap
            // so if we have a el smaller than our k starting elements it can never be in our ans so pop it
            if (pq.size() > k) pq.pop();
        }
        
        // make ans vector of size k, now our pq wil be of size k so we push all elements
        // since in pq max el will be at first and we pop from back so push n dec order in ans
        vector <string> ans(k);
        while (!pq.empty()) {
            ans[--k] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
