// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

/*
struct Item{
    int value;
    int weight;
};

The greedy method to maximize our answer will be to pick up the items with higher values. 
Since it is possible to break the items as well we should focus on picking up items having higher 
value /weight first. To achieve this, items should be sorted in decreasing order with respect to their 
value /weight. Once the items are sorted we can iterate. Pick up items with weight lesser than or equal 
to the current capacity of the knapsack. In the end, if the weight of an item becomes more than what 
we can carry, break the item into smaller units. Calculate its value according to our current capacity 
and add this new value to our answer.
*/
class Solution {
    public:
    
    // comparator to sort acc to value / weight
    // will return true if items sorted in value/weight fashion else false
    bool static comparator (Item a, Item b) {
        
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        
        return r1 > r2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n) {
        
        // sort array acc to value/weight in decreasing order of value/weight to maximise result
        sort (arr, arr + n, comparator);
        
        // weight will have accumulated weight till now, ans hold the result or max value
        int weight = 0;
        double ans = 0.0;
        
        // iterate in sorted array
        for (int i = 0; i < n; i++) {
            
            // add value to ans and accumulate weight till our total weight and current weight is within range <= W
            if (weight + arr[i].weight <= W) {
                weight += arr[i].weight;
                ans += arr[i].value;
            }
            // if we reach else means either 0 weight left or partial weight left
            // find out the remaining weight W - weight
            // multiply ratio of weight left / current weightwith the value to get partial value
            // add in ans and break since weight will get 0 here, if already 0, temp will have 0 value
            else {
                int temp = W - weight; // remaining weight
                ans += (double)arr[i].value * ((double)temp / (double)arr[i].weight);
                break;
            }
        }
        return ans;
    }
};
