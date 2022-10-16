/*
largest subarray with two elements

we maintain a hashmap in which we add fruit type and its freq
we inc window length till map size <= 2

if map size incresed > 2, we start dec window length from left pointer
if freq > 1 just dec freq 
and if freq = 1 ,delete that element from map 

do map operation till size become <= 2 again

at each uteration of r we calculate window ength and compare with max as current window will hold a valid subarray
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int minFruit = INT_MAX, ans = 0;
        unordered_map<int, int> mp;

        // left right pointers to create window
        for (int l = 0, r = 0; r < fruits.size(); r++) {
            
            // add rpointer fruit in map
            mp[fruits[r]]++;

            // condition when subarray has more than 2 elements
            // remove elements from window left till size <= 2
            if (mp.size() > 2) {

                if (mp[fruits[l]] == 1) mp.erase(fruits[l]);
                else mp[fruits[l]]--;
                l++;
            }
            // compute max window length 
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
