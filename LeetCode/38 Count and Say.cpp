/*
we need to count in the previous result and from next result using that
*/

class Solution {
public:
    string countAndSay(int n) {

        // base result when n = 1
        string res = "1";

        // pre decrement as we already formed result for n = 1
        while(--n) {

            // make new result in currRes
            string currRes = "";

            // iterate in result
            // traverse and count no. of repeating characters
            // push the count and that character in new res
            // for 1211 -> 11 pushed in 1st it, 12 pushed in 2nd it, 21 pushed in 3rd it
            // so currres = 111221
            for(int i = 0; i < res.size(); i++) {

                int count = 1;

                // counting same elements 
                while(i + 1 < res.size() && (res[i] == res[i + 1])) {
                    count++;
                    i++;
                } 
                // pushing count and character
                currRes.push_back(count + '0');
                currRes.push_back(res[i]);
            }
            // update res to new one
            res = currRes;
        }
        return res;
    }
};
/*
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221 
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
 10.    13211311123113112211
*/
