// https://leetcode.com/contest/biweekly-contest-87/problems/minimum-money-required-before-transactions/

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        
        // loss is the money which we need to spend when money > cashback
        // for every loss also calculate max cashback till now
        long long loss = 0;
        int maxCB = 0;
        
        for (auto a :transactions){
            
            // taking out values of money and cashback
            int money = a[0];
            int cashback = a[1];
            
            // compute loss and max cashback value
            if (money > cashback){
                loss += (money - cashback);
                maxCB = max(maxCB, cashback);
            }
        }
        // now for the case when there is no loss means money <= cashback
        // we just need to get the max of money in those cases to deal will all transaction without problem
        int maxMONEY = 0;
        
        for (auto a :transactions){
            
            // taking out values of money and cashback
            int money = a[0];
            int cashback = a[1];
            
            // compute max money req to pass transactions
            if (money <= cashback){
                maxMONEY = max(maxMONEY, money);
            }
        }
        
        long long ans = loss + max(maxMONEY, maxCB);
        return ans;
        
    }
};
//________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________
// compact solution - USING JUST ONE LOOP
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        
        // loss is the money which we need to spend when money > cashback
        // for every loss also calculate max cashback till now
        long long loss = 0;
        int maxtr = 0;
        
        for (auto a :transactions){
            
            int money = a[0];
            int cashback = a[1];
            
            // compute loss and max cashback value
            if (money > cashback){
                loss += (money - cashback);
                maxtr = max(maxtr, cashback);
            }
            // now for the case when there is no loss means money <= cashback get maxMoney in maxtr
            else{
                maxtr = max(maxtr, money);
            }
        }
        return loss + maxtr;
        
    }
};
