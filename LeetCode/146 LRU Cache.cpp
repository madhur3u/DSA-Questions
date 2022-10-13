class LRUCache {
public:

    unordered_map <int, list <pair<int, int>>::iterator> mp;
    list <pair<int, int>> lru;
    
    int size, count = 0;

    LRUCache(int capacity) { size = capacity; }

    // if key not in map -1
    // else push the pair in list to 1s pos and return its value
    int get(int key) {
        
        if (mp.find(key) == mp.end()) return -1;

        lru.splice(lru.begin(), lru, mp[key]);
        return lru.front().second;
    }
    
    // when putting value 
    void put(int key, int value) {

        // if same key exist update its value and push to front
        if (mp.find(key) != mp.end()) {

            lru.splice(lru.begin(), lru, mp[key]);
            mp[key] -> second = value;   
            return; 
        }
        // if size full then erase element at back, rease from map
        if (count == size) {

            int k = lru.back().first;
            lru.pop_back();
            mp.erase(k);
            count--;
        }
        // push new element to front also add in map
        lru.push_front({key, value});
        mp[key] = lru.begin();
        count++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
