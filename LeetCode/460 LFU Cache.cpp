// https://leetcode.com/problems/lfu-cache/solutions/937737/c-o-1-time-complexity-with-algorithm/
// https://www.youtube.com/watch?v=0PSB9y8ehbk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=80

struct Node {
    int value;
    list<int>::iterator it;
};

class LFUCache {
public:

    int size, lowestFreq = 0;

    // this map will store key and Node will have value and iterator to that key in list
    unordered_map<int, Node> mp_val;
    // this map stores key and the count of thier frequency
    unordered_map<int, int> mp_key_freq;
    // this map will have freq as the keys and the keys which are at that freq in value arranged in LRU
    unordered_map<int, list<int>> mp_freq_keyList;

    LFUCache(int capacity) { size = capacity; }
    
    int get(int key) {

        if (mp_val.find(key) == mp_val.end()) return -1;

        // update freq by sending it to put fn again, since key already present so 1st if block runs in put
        // it will update freq, value will be updated to same value as we send same value
        put(key, mp_val[key].value);
        return mp_val[key].value;
    }
    
    void put(int key, int value) {

        // when capacity is zero 
        if (size == 0) return;

        // when key already present
        // we update the value and freq of that key
        if (mp_val.find(key) != mp_val.end()) {

            // delete the key from list using iterator
            // so we first access the list at the freq of our key, then we access iterator from val node map and delete that iterator
            mp_freq_keyList[mp_key_freq[key]].erase(mp_val[key].it); 

            // checking if the list from which we deleted is now empty or not
            // if it is empty we will delete this freq from freq-list-map 
            if (mp_freq_keyList[mp_key_freq[key]].empty()) {
                
                // if the lowest frew was of this element which we deleted and list now empty
                // lowest freq will increase to the next freq
                if (lowestFreq == mp_key_freq[key]) lowestFreq++;

                // removing the key-list from map as list empty, deleteing that freq from map
                mp_freq_keyList.erase(mp_key_freq[key]);
            }
            mp_val[key].value = value;  // updte value in value map
            mp_key_freq[key]++;         // inc the freq by 1
            mp_freq_keyList[mp_key_freq[key]].push_front(key);              // for new freq add this key in front of list, LRU algo
            mp_val[key].it = mp_freq_keyList[mp_key_freq[key]].begin();     // update iterator in values map to the begin of new list where we pushed key
            return;
        }
        // key diff a new key has to be inserted
        // if max capacity reahced, we need to delete lru of lowest freq
        if (mp_val.size() == size) {
            
            // extract key to be deleted using lowest freq, it will be lru in lost freq list, means last element of list in lowest freq
            // extract key and delete from the list
            int keyToDelete = mp_freq_keyList[lowestFreq].back();
            mp_freq_keyList[lowestFreq].pop_back(); 

            // if after deleteing lfu, list at lowest freq is empty we delete that freq from our list
            if (mp_freq_keyList[lowestFreq].empty()) 
                mp_freq_keyList.erase(lowestFreq);
            
            mp_val.erase(keyToDelete);
            mp_key_freq.erase(keyToDelete); // delete the key fro other 2 maps as this ey does not exist anymore
        }
        // irrespective of if above if condition runs, now we need to add a new key at freq 0 since this is a new key
        lowestFreq = 0;                                     // this element come 1st time so now lowest freq is set to 0 
        mp_key_freq[key] = 0;                               // update freq in freq map for key
        mp_freq_keyList[0].push_front(key);                 // push this element at begin of 0th freq list, lru
        mp_val[key].value = value;                          // update value
        mp_val[key].it = mp_freq_keyList[0].begin();        // update iterator
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
