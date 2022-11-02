class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        // make set of bank, if end doesnt exist in bank return -1
        unordered_set<string> set{bank.begin(), bank.end()};
        if (!set.count(end)) return -1;

        queue<string> q;    // q for bfs
        q.push(start);      // push start
        int mutations = 0;  // mutation count

        while (!q.empty()) {

            int size = q.size();    // iterate till current size
            while (size--) {

                // extract the front element and pop, if this is == end means reached ans return mutations
                string curr = q.front(); q.pop();
                if (curr == end) return mutations;

                set.erase(curr);    // erase the curr string from bank to avoid redundant checking

                // for curr string, change each character in curr
                // and check if any of the changed string exist in bank
                // at each index we check the possibility of mutation by replcaing it with A,C,G,T
                // push in q if exist, 8*4 -> 32 times below loop will run, ACGT as -> 4 times
                for (int i = 0; i < 8; i++) {

                    string temp = curr;
                    temp[i] = 'A';
                    if (set.count(temp)) q.push(temp);
                    temp[i] = 'C';
                    if (set.count(temp)) q.push(temp);
                    temp[i] = 'G';
                    if (set.count(temp)) q.push(temp);
                    temp[i] = 'T';
                    if (set.count(temp)) q.push(temp);
                }
            }
            mutations++;
        }
        return -1;
    }
};
