class KthLargest {
public:
    // min heap stores values in dec order
    // so we keep the kth largest element in the last and pop if pq size > k
    priority_queue <int, vector<int>, greater<int>> pq;
    int K;

    // forming initial pq
    KthLargest(int k, vector<int>& nums) {
        K = k;

        // add each number in pq, pop when more than k elements pushed as the no. popped will be smaller so we wont need it
        for (int n : nums) {
            pq.emplace(n);
            if (pq.size() > K) pq.pop();
        }
    }
    
    // aad val, pop if needed, return top
    int add(int val) {
        pq.emplace(val);
        if (pq.size() > K) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
