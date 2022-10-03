/*
logic : in a agroup will will add all cost to ans except the max cost
like we have 4 a's of aaaa --> 1 2 3 4
in ans we first add all --> ans = 1 + 2 + 3 + 4 = 10
we store max in group in maxT --> 4
we the subtract maxT from ans --> ans = 10 - 4 = 6 --> cost of removing 3 a's with min time 
*/

class Solution {
public:
    int minCost(string col, vector<int>& time) {

        int n = col.size();

        // setting ans and max as the 1st element in string
        int ans = time[0], maxT = time[0];

        // iterate from 1st el till end
        for (int i = 1; i < n; i++){

            // when unequal elements first we remove the maxT from ans
            // this could be the time[0] if this is 1st iteration
            // or after aaaa we may have b --> aaaab means now we subtract maxT i.e. 4 in above ex
            // set maxT to zero
            if (col[i - 1] != col[i]){
                ans = ans - maxT;
                maxT = 0;
            }

            // add time to ans
            // update maxT
            // if from next it we found equal elements we are forming our max and ans
            // if we find unequal again it will be subtracted in the if block above
            ans = ans + time[i];
            maxT = max(maxT, time[i]); 
        }

        // for case when equal el till last ex. abcddddd
        // maxT was not removed as loop had ended so remove that
        // we also need to remove that in case of unequal elements as we have added it in ans after if block 
        return ans - maxT;
    }
};

/* TWO POINTER APPROACH : 1ST INTUTUION
public:
    int minCost(string col, vector<int>& time) {

        int n = col.size();

        int i = 0, j = 1, minTime = 0;

        while (j < n){

            while (col[i] == col[j]){
                if (time[i] < time[j]){
                    minTime += time[i];
                    i = j;
                    j++;
                }
                else{
                    minTime += time[j];
                    j++;
                }
            }
            i = j;
            j++;
        }
        return minTime;
    }
};
*/
