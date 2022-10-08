/*
https://leetcode.com/problems/online-stock-span/solutions/2643474/online-stock-span/
Push every pair of <price, result> to a stack.
Pop lower price from the stack and accumulate the count.
*/

class StockSpanner {
public:
    // store prices in stack in dec order (monotonically decreasing stack) with the count of ans  
    stack<pair<int, int>> st;
    StockSpanner() { }
    
    int next(int price) {
        
        // set ans = 1 default when no smaller to current price found
        int ans = 1;

        // check in stack if a lower or equal price is present
        // add its count to ans and pop that lower price 
        // loop till condition satisfy
        while (!st.empty() && price >= st.top().first){
            ans = ans + st.top().second;
            st.pop();
        }
        // push the current el and its ans to stack
        st.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
