class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        // count of five and ten bills
        int five = 0;
        int ten = 0;

        for (int bill : bills) {

            // if its a 5 just inc five
            if (bill == 5) five++;

            // if 10, we give 5 so dec five and inc 10
            else if (bill == 10) {
                ten++;
                five--;
            }

            // if its a 20
            else {
                // if we have 10, we give 1 ten and 1 five
                if (ten > 0) {
                    ten--;
                    five--;
                }
                // else we give 3 five
                else {
                    five -= 3;
                }
            }
            // if five < 0 means we cannot give customer change so return false
            if (five < 0) return false;
        }
        return true;
    }
};
