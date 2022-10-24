class Solution {
public:
    int ans = 0;
    int maxLength(vector<string>& arr) {
        dfs(arr, 0, "");
        return ans;
    }

    void dfs(vector<string>& arr, int idx, string str) {

        // base case return if the current string is not unique
        if (!unique(str)) return;

        // we reach here only if our string is unique so we update ans 
        ans = max(ans, (int)str.size());

        // include all strings from index till end and make recursive call (take condition)
        // if the formed str is invalid it will return (not take condition)
        for (int i = idx; i < arr.size(); i++) {
            dfs (arr, i + 1, str + arr[i]);
        }
    }

    // this will tell us if all characters in the given string are unique or not
    // we push chars to set and check if a char was previously present before pushing
    bool unique(string &str) {
        unordered_set <char> s;
        for (char ch : str) {
            if (s.find(ch) != s.end()) return false;
            s.insert(ch);
        } 
        return true;
    }
};
