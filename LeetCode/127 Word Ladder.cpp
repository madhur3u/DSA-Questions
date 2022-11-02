// https://leetcode.com/problems/word-ladder/solutions/1764371/a-very-highly-detailed-explanation/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = beginWord.size();
        unordered_set<string> words{wordList.begin(), wordList.end()};  // make set of all words
        if (!words.count(endWord)) return 0;                            // if end not in words
        
        queue<string> q;            // q for bfs
        q.push(beginWord);          // add start word
        int steps = 1;              // initial step is 1 as current is also incuded in ans see example

        while (!q.empty()) {

            int size = q.size();    // iterate till size
            while (size--) {

                string curr = q.front(); q.pop();   // extract the front string and pop
                if (curr == endWord) return steps;  // if we reached end Word retr=urn no. of steps

                // now we are going to try all possible combinations for the curr word
                // for that we change each character from i to n of curr with a-z
                // means loop run for n * 26 times
                // if the modified word is present in list
                // push mod word in q and remove from list to avoid redundancy
                // this way we will get all combinations and will be able to find when we have reached end
                for (int i = 0; i < n; i++) {
                    string temp = curr;
                    for (char c = 'a'; c <= 'z'; c++) {

                        temp[i] = c;
                        if (words.count(temp)) {
                            q.push(temp);
                            words.erase(temp);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};
