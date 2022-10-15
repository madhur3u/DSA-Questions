class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> res, power;
        
        // since we are guaranteed that n can be represented by power of 2
        // so we will make the power array first from reverse so we can get min no. of powers of 2
        // for 15, we take the 1st value as 8 (computed using log2(n))
        // new n = 15 - 8 = 7 arr = [8] , next for n = 7, value less than 7, 4
        // new n = 7 - 4 = 3, arr = [8, 4] next for 3 -> 2
        //     n = 3 - 2 = 1, arr = [8, 4, 2] next for 1 -> 1, 2^0
        //     n = 1 - 1 = 0, arr = [8, 4, 2, 1] our array formed
        // 2^x can be computed efficiently using bit manip, shift 1 by pow 
        while (n != 0) {
            int pow = log2(n);
            power.push_back(1 << pow);
            n = n - (1 << pow);
        }
        // reverse array formed -> [1,2,4,8]
        reverse(power.begin(), power.end());
        
        // now we just need to multiply indices value as given in query and push in result
        for (auto q : queries) {
            
            long long p = 1;
            for (int i = q[0]; i<=q[1]; i++) 
                p = (p * power[i]) % 1000000007;    

            res.push_back(p);
        }
        return res;
    }
};
