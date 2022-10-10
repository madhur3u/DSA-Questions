class Solution {
public:
    string removeKdigits(string num, int k) {
        
        // monotonic inc stack will help in finding sol
        stack <char> st;

        // case when n == k
        if (num.size() == k) return "0";

        // iterate in string and form a inc stack till all k spent
        for (char ch : num) {

            while (k > 0 && !st.empty() && ch < st.top()){
                st.pop();
                k--;
            } 
            // this will prevent in pushing 0 when stack is empty
            // so we wont have leading zeroes in base of final stack
            if (!st.empty() || ch != '0') st.push(ch);
        }

        // for case when string is inc like 123456
        // inner while loop wont run so k not reduced
        // so pop elements if k is left
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // answer formation, add to new string reverse that and return
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        // if ans is empty we return "0" and not empty string
        return ans.size() ? ans : "0";
    }
};
