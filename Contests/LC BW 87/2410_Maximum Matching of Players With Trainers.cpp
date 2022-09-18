// https://leetcode.com/contest/biweekly-contest-87/problems/maximum-matching-of-players-with-trainers/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        // sort both arrays
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        // two pointers at beg of both arrays
        int i = 0, j = 0, ans = 0;
        
        // run till element left in either of the array
        while (i < players.size() && j < trainers.size()){
            
            // if player ability is more, inc the trainer array pointer only
            if (players[i] > trainers[j]) j++;
            
            // player's ability is less than or equal to the trainer's training capacity
            // inc ans, move both pointers
            else if (players[i] <= trainers[j]){
                ans++;
                i++;
                j++;
            }
        }
        return ans;
    }
};
