class Solution {
public:
    long long subArrayRanges(vector<int>& a) {

        int n = a.size();
        vector<int> left_max(n), left_min(n), right_max(n), right_min(n);
        stack<int> st_min, st_max;

        for (int i = 0; i < n; i++) {

            while (!st_min.empty() && a[st_min.top()] > a[i]) {
                st_min.pop();
            }
            left_min[i] = st_min.empty() ? i + 1 : i - st_min.top();
            st_min.push(i);

            while (!st_max.empty() && a[st_max.top()] < a[i]) {
                st_max.pop();
            }
            left_max[i] = st_max.empty() ? i + 1 : i - st_max.top();
            st_max.push(i);
        }
        // empty stacks O(n)
        while (!st_min.empty()) st_min.pop();
        while (!st_max.empty()) st_max.pop();

        for (int i = n - 1; i >= 0; i--) {

            while (!st_min.empty() && a[st_min.top()] >= a[i]) {
                st_min.pop();
            }
            right_min[i] = st_min.empty() ? n - i : st_min.top() - i;
            st_min.push(i);

            while (!st_max.empty() && a[st_max.top()] <= a[i]) {
                st_max.pop();
            }
            right_max[i] = st_max.empty() ? n - i : st_max.top() - i;
            st_max.push(i);
        }
        // for (int a1 : left_min) cout<<a1<<" ";
        // cout<<endl;
        // for (int a1 : right_min) cout<<a1<<" ";
        // cout<<endl;
        // for (int a1 : left_max) cout<<a1<<" ";
        // cout<<endl;
        // for (int a1 : right_max) cout<<a1<<" ";
        // cout<<endl;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (long long)a[i]*(((long long)left_max[i]*right_max[i]) - ((long long)left_min[i]*right_min[i])); 
        }
        return ans;
    }
};
