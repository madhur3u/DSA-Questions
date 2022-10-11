class Solution {
public:
    // this fn finds the max reactangle area in a histogram
    // using the prev and next min method
    int largestRectangleArea(vector<int>& h) {
        
        stack<int> st;
        int res = 0, n = h.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || h[st.top()] > h[i])) {
                int currIndex = st.top(); st.pop();
                int nextIndex = i;
                int prevIndex = (st.empty()) ? -1 : st.top();

                res = max(res, h[currIndex]*(nextIndex - prevIndex - 1));
            }
            st.push(i);
        }
        return res;
    }

    // logic is to make histogram using the biary 2d array for each row
    // We can apply the maximum in histogram in each row of the 2D matrix. 
    // What we need is to maintain an int array for each row, which represent for the height of the histogram.
    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<int> histogram(matrix[0].size(), 0);
        int res = 0;

        // take each row in a 1d array
        for (auto row : matrix) {

            // for each row update the histogram matrix
            // if 0 in row[i] then make hist[i] also 0
            // if 1 in row[i] add 1 to current hist[i] value
            for (int i = 0; i < row.size(); i++)
                histogram[i] = (row[i] == '1') ? histogram[i] + 1 : 0;

            // compute the max rectangle area and compare with prev res to get max
            res = max (res, largestRectangleArea(histogram));
        }
        return res;
    }
};
/*
Suppose there is a 2D matrix like

1 1 0 1 0 1

0 1 0 0 1 1

1 1 1 1 0 1

1 1 1 1 0 1

First initiate the height array as 1 1 0 1 0 1, which is just a copy of the first row. 
Then we can easily calculate the max area is 2.

Then update the array. We scan the second row, when the matrix[1][i] is 0, set the height[i] to 0; 
else height[i] += 1, which means the height has increased by 1. So the height array again becomes 0 2 0 0 1 2. 
The max area now is also 2.

Apply the same method until we scan the whole matrix. 
The last height arrays is 2 4 2 2 0 4, so the max area has been found as 2 * 4 = 8.

Then reason we scan the whole matrix is that the maximum value may appear in any row of the height.
*/
