// https://leetcode.com/problems/task-scheduler/solutions/760131/java-concise-solution-intuition-explained-in-detail/
// EXPLANATION ABOVE
// space -> O(26) ~ O(1)
// time -> O(n) + O(26*log26) [constant] -> ~O(n)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // make freq array for all tasks
        vector<int> freq(26, 0);
        for (char ch : tasks) freq[ch - 'A']++;

        // sort freq array and take max - 1
        // no. of spaces we can have are (max - 1)*n since we do not need to add space after last task
        // eg in AAABBC -> max = 3, n = 2, -> A _ _ A _ _ A
        // SPACES = (3 - 1) * 2 = 4
        sort(freq.begin(), freq.end());
        int maxfreq = freq.back() - 1;
        int spaces = maxfreq * n;

        // now we subtract all elements which we can accomodate in spaces from spaces
        // so reduce the spaces using other elements here
        // if we found a element freq same as max then we subtract maxfreq (max - 1) rather than max
        // as we cannot accomodate 3 B between 3 A's in AAABBB type question so we leave one more space to push it in last
        for (int i = 24; i >= 0; i--) 
            spaces -= min(maxfreq, freq[i]);
        
        // final ans will be, no. of elements in tasks + no. of +ve spaces left
        return tasks.size() + max(0, spaces);
    }
};
