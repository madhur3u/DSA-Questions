// logic : for each element -> a find no. of subarrays in which it is minimum -> x 
// find no. of elements in which it is maximum -> y
// for el a -> a{y - x}
// do this for all elements

class Solution {
public:
    long long subArrayRanges(vector<int>& a) {

        // make 2 stack inc monotonic stack to find next and prev minimum
        // dec monotonic stack to find next and prev maximums
        int n = a.size();
        stack<int> inc, dec;
        long long res = 0;

        // traverse in vector a
        // run till n, why? as when we have completed all iteration stack might still has some elements
        // so for that we just pop it and for those el max index will be set to i for easy calculation 
        for (int i = 0; i <= n; i++) {  

            // prev and next min 
            // when we found a element < st.top
            // then the element below it is the prev min and the element in a[i] next min
            // using indices of both calculate no. of subarrays where a[currIdx] is minimum
            while (!inc.empty() && (i == n || a[inc.top()] > a[i])) {
                
                int currIdx = inc.top(); inc.pop();
                int prevMinIdx = inc.empty() ? -1 : inc.top();
                int nextMinIdx = i;

                // since min has to be subtracted therefore res -= 
                res -= (long long) a[currIdx] * (currIdx - prevMinIdx) * (nextMinIdx - currIdx); 
            }
            // same logic for prev and next max
            while (!dec.empty() && (i == n || a[dec.top()] < a[i])) {

                int currIdx = dec.top(); dec.pop();
                int prevMaxIdx = dec.empty() ? -1 : dec.top();
                int nextMaxIdx = i;

                // we need to add if maximum
                res += (long long) a[currIdx] * (currIdx - prevMaxIdx) * (nextMaxIdx - currIdx);
            }

            // push the index i in both stacks for next iteration
            inc.push(i);
            dec.push(i);
        }
        return res;
    }
};
