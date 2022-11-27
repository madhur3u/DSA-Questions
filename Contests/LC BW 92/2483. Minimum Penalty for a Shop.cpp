/*
Instead of computing penalty, we can compute total profit for the shop being open up to a certain hour, 
then choose the hour that gives the maximal profit.
*/
class Solution {
public:
    int bestClosingTime(string s) {
        
        int n = s.size();
        int profit = 0, max = 0, ans = 0;

        // iterate in string
        for (int i = 0; i < n; i++) {

            if (s[i] == 'Y') profit++;      // if y we inc profit
            else             profit--;      // else dec profit

            // if the profit > max profit till now, so we can choose ans as i + 1th hour as this is the max profit till now
            if (profit > max) {             
                max = profit;       // update max and ans
                ans = i + 1;
            }
        }
        return ans;
    }
};
