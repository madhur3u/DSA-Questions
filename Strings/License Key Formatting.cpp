// https://practice.geeksforgeeks.org/problems/license-key-formatting/1

class Solution
    {
    public:
        string ReFormatString(string s, int k){
        
        // pushback popback are faster than normal adding characters so prevents TLE
        // this will have our answer
        // count will be used to check how many cahrs have been pushed in ans and compare with k
        string ans = "";
        int count = 0;
        
        // traverse from end
        for (int i = s.size() - 1; i >= 0; i--){
            
            // if a dash found continue
            if (s[i] == '-') continue;
            
            // pushing s[i] to ans afterconverting to uppercase if lower
            // inc count 
            s[i] = (islower(s[i])) ? toupper(s[i]) : s[i];
            ans.push_back(s[i]);
            count++;
            
            // if count == k we push a dash in our ans
            // i > 0 to check for case when size % k == 0
            // we do not want a extra dash in our ans
            if (count == k && i>0){
                ans.push_back('-');
                count = 0;
            }
        }
        // for case if dash was present in our string in strating
        // we check if a dash is in our ans if yes delete that
        // reverse th ans to obtain desired ans
        if (ans.back() == '-') ans.pop_back();
        reverse(ans.begin(), ans.end());
    	return ans;
    }
};
