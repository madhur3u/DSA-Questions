class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size(), m = t.size();
        if (m > n) return "";
        
        // we need to find the starting index and the length of the minimum window
        int min_window_size = INT_MAX;
        int start = 0;

        // store freq of all elements of t in a map
        unordered_map<char, int> mp;
        for (auto i : t) mp[i]++;

        // make a variable equal to size of map
        int count = mp.size();

        // sliding window loop
        for (int l = 0, r = 0; r < n; r++) {

            // reduce freq of the current element
            // if it was a element from t then the freq will dec as freq >= 1
            // so when it come to zero(as t may have repeated el) we dec count
            // else if it was not in t it will become -ve and we wont consider that
            mp[s[r]]--;
            if (mp[s[r]] == 0) count--;

            // for the case when we have found a valid window with all t elements
            while (count == 0) {

                // check if this window is smaller than found till now
                // update size and start point if true
                if (min_window_size > r - l + 1) {
                    min_window_size = r - l + 1;
                    start = l;
                }

                // inc freq of element we are now removing from window
                // count will be inc when we inc freq of element in t and for that freq will get > 0
                mp[s[l]]++;
                if(mp[s[l]] > 0) count++;
                
                l++;
            }
        }
        // if we never found a valid window size = intmax so return "", else return substring
        return (min_window_size == INT_MAX) ? "" : s.substr(start, min_window_size);
    }
};
