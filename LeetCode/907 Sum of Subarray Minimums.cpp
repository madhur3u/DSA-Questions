class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        
        // we make 2 vectors left and right which store prev/next min from left and right resp for each i
        // for next minimum element we use stack to compute that
        int n = a.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // finding previous minimum for a particular index in array
        // we are going to store the index of the prev min in stack and left vector
        // if no prev min exist push -1 to left vector
        // O(n)
        for (int i = 0; i < n; i++) {

            while (!st.empty() && a[st.top()] > a[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        // empty stack O(n)
        while (!st.empty()) st.pop();

        // finding next min element for each element in a
        // if no next min push 'n' to right vector
        // O(n)
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && a[st.top()] >= a[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // long to prevent overflow
        // now we need to find in how many subarray a[i] will be minimum
        // for that we need distance from its prev and next min
        // (i - left[i]) is the no. f subarray to left in which a[i] is minimum
        // (right[i] - i)) for right
        // in case it is min in either left or right we have fiven it -1 and n so no extra if else needed
        // multiply both distance with a[i] and add to ans
        // we are considering equal elements in right array and not in left array
        // O(n)
        long  ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (long)(ans + (long)a[i]*(i - left[i])*(right[i] - i)) % 1000000007; 
        }
        return ans;
    }
};
/*
time ~ O(n)
space ~ O(n)

left and right has index of prev and next minimum

index -  0  1  2  3  4  5  6  7  
array - [1, 7, 6, 3, 1, 2, 2, 4]
left  - -1  0  0  0  0  4  5  6
right - -1  2  3  4 -1 -1 -1 -1
*/
