class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& a) {
        
        vector<vector<int>> ans;
        int i = 0;

        // adding all intervals occuring before start of the interval to be added
        while (i < A.size() && a[0] > A[i][1]) 
            ans.emplace_back(A[i++]);

        // meging the new interval and all intervals which are coinciding with it
        // update new interval formed in a
        while (i < A.size() && a[1] >= A[i][0]) {
            a[0] = min(a[0], A[i][0]);
            a[1] = max(a[1], A[i][1]);
            i++;
        }
        ans.emplace_back(a);    // push the updated interval to the ans

        // push the remaining intervals
        while (i < A.size()) 
            ans.emplace_back(A[i++]);

        return ans;
    }
};
