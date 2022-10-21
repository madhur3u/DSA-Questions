class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // store freq of each no. in a map
        unordered_map <int, int> mp;
        for (int num : nums) mp[num]++;

        // min heap of pair, to keep freq and element 
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // iterate in map and push freq first then element
        // pop if size of pq > k, since after that we will have less frequent element than k so dont need that
        for (auto it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > k) pq.pop();
        }

        // ans vector, push elements present in pq
        vector <int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
