// https://leetcode.com/problems/sort-characters-by-frequency/
/*
Time Complexity: O(n)
O(26log(n)) = O(log(n)) For Construction and extraction from heap
O(n) For storing the frequency in hashmap.
*/

class Solution {
public:
    string frequencySort(string s) {
        
        int n = s.size();
        
        // we first make a unorderd map which will map all chars with its freq
        // we cannot use this diretly as it is not in order
        unordered_map<char, int> char_freq;
        for (char ch : s) char_freq[ch]++;
        
        // making a maxheap
        // maxheap store the values such that the max value is on top, popped first
        // therefore we store freq as first element of pair
        priority_queue <pair<int, char>> pq;
        
        // putting pairs in maxheap
        for (auto [ch, freq] : char_freq)
            pq.push({freq, ch});
        
        // ths will hold ans
        string ans;
        
        // run till heap is empty
        // freq -> pq.top().first, character -> pq.top().second
        // pop the topmost pair to get next one in next teration
        while (!pq.empty()){
            ans.append(pq.top().first, pq.top().second);
            pq.pop();
            // ans = ans + string(freq, ch);
        }
        return ans;
    }
};
