// O(N) time, O(N) space

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector <int> c(n, 1); // initialize candy array with all 1 as min 1 candy with everyone

        // update candy array from left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) c[i] = c[i - 1] + 1;
        }
        // update candy array from right to left
        // c[i] = max(c[i], c[i + 1] + 1), as c[i] current might be > c[i+1]+1 from prev loop
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) c[i] = max(c[i], c[i + 1] + 1);
        }
        // return sum of candy array
        return accumulate(c.begin(), c.end(), 0);
    }
};

/*
Used greedy aproach:

    every student should get atleast one so initially give 1 candy to every student
    
    Now traverse left to right, whenever we get a higher rating, it should get more candy from its 
    neighbour( left neighbour in the curr case) so give just one more candy than its left neighbour
    
    Now another case left when its right neighbour has higher rating, traverse from right, and if we get 
    a higher rating, give it max(curr, 1+candy of its right). max ensures that for local maxima candies 
    should be high than both neighbours;
*/
