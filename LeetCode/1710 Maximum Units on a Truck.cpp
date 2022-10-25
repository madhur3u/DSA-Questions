class Solution {
public:

    // comparator to sort array in inc no.of second element of vector
    bool static comparator (vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int n = boxTypes.size();
        // sort in inc order of the 2nd element using comparator
        sort(boxTypes.begin(), boxTypes.end(), comparator);

        int ans = 0;
        // iterate in sorted vector
        for (vector<int> box : boxTypes) {
            
            // x will be the min capacity we can have from availiabe capacity trucksize and no.ofboxes
            int x = min(box[0], truckSize);
            // add total no. of current units in ans using x
            ans += x * box[1];
            // subtract x from capacity
            truckSize -= x;
            // if capacity reach zero break
            if (!truckSize) break;
        }
        return ans;
    }
};
