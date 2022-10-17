// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/solutions/597825/simple-clean-intuitive-explanation-with-visualization/
// SEE IMAGE VISUALIZATION FROM ABOVE LINK

/*
since we need to take elements from extremes so window length will be k
suppose we take x elements from left and y from right then x + y = k

so we take all k elements only from left first -> leftSum
store this in result

now we will have 2 sub windows -> left with k length, right with 0 length
iterate from 0 to k
dec left window length by reducing sum (subtract right most element of window)
inc right window by inc rightSum (add leftmost element before window)

remember x + y == k always true, means both subwindow length sum == k 
*/

class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        
        int n = cards.size();

        // compute left sum of k elements
        int leftSum = 0, rightSum = 0;
        for(int i = 0; i < k; i++) leftSum += cards[i]; 

        // store 1st result
        int res = leftSum + rightSum;

        // iterate k times, dec leftsum, inc rightsum
        // compute res max 
        for(int i = 0; i < k; i++) {
            leftSum -= cards[k - i - 1];
            rightSum += cards[n - i - 1];

            res = max(res, leftSum + rightSum);
        }
        return res;
    }
};
