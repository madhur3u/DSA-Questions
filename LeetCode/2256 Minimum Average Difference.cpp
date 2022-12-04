typedef long long ll;
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n = nums.size();

        // make prefix sum array ps
        vector<ll> ps(n);
        ps[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ps[i] = ps[i - 1] + nums[i];
        }
        // sum of all elements of array
        ll sum = ps.back();

        // we tr to make ans from last
        // so store n-1 in min and average as avg at last index as sum/n
        int min = n - 1;
        ll minAvg = sum/n;

        // already computed for last index so start from n - 2th index till 0
        for (int i = n - 2; i >= 0; i--) {

            ll a = ps[i] / (i + 1);                 // compute both parts (as given in problem)
            ll b = (sum - ps[i]) / (n - i - 1);     // suffix sum can be made using sum - prefix sum at i

            ll currAvg = abs(a - b);                // calculate avg
            if (currAvg <= minAvg) {                // minimise ans
                minAvg = currAvg;
                min = i;
            }
        }
        return min;
    }
};
