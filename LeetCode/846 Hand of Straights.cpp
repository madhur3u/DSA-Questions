// https://www.youtube.com/watch?v=amnrMCVd2YI
/* O(N*logN)
make a count map for all elements and place all keys in a minHeap
now we take the 1st min element of array (minheap top) and check if all consecutive elements exist in map
for that we loop till min till min + groupSize
dec the count of the digit we are including in a group

if any count become zero, check if it is min element or not
if it is not a min element, not equal to top
then we have a number whose count is now zero but the no. previous to it have +ve count
means we cannot make consecutive element now so return false
same return false if consecutive el not found
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        // size of array should be divisible by groupsize
        if (hand.size() % groupSize != 0) return false;

        // map for count, minheap
        unordered_map <int, int> count;
        priority_queue <int, vector<int>, greater<int>> minHeap;

        // make count map using array, and minHeap using map (so we dont include dupicates in minHeap)
        for (int card : hand) count[card]++;
        for (auto it : count) minHeap.emplace(it.first);

        // run till minheap is empty
        while (!minHeap.empty()) {

            // extract the first element, current min element 
            int first = minHeap.top();
            
            // now we will check if all consecutive elements are present in our array for current minimum
            for (int i = first; i < first + groupSize; i++) {

                // if any consecutive element not found in map, return false cant form valid groups
                if (count.find(i) == count.end()) 
                    return false;

                // dec count as we found the el
                count[i]--;

                // when count reach zero we need to remove it from minheap also
                // check if it is min el pop it, else return false
                if (count[i] == 0) {
                    if (i != minHeap.top()) return false;
                    minHeap.pop();
                }    
            }
        }
        return true;
    }
};
