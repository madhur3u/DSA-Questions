class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() { }
    
    // making our map, we store the time and value in vector
    // as given in constrains timestamps are always increasing
    // so vector will be sorted in inc order acc to timestamp
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    // now we need to get the timestamp for the given key
    // if it does not exist we get the previous ex. timestamp = 3 and in mp[key] we have 1 
    // we will print value of 1 but not vice versa, so we can print its floor timestamp's value in vector
    string get(string key, int timestamp) {

        // if key does not exist return empty string 
        if (!mp.count(key)) return "";

        // binary search to find floor of a number
        int l = 0, r = mp[key].size() - 1;
        
        while (l <= r){
            int mid = (l + r) >> 1;
            if (mp[key][mid].first == timestamp)        return mp[key][mid].second; // if timestamp found 
            else if (mp[key][mid].first < timestamp)    l = mid + 1;
            else                                        r = mid - 1;
        }
        // if r < 0 means floor does not exist we return empty string 
        // else we return the value stored in rth timestamp 
        return (r < 0) ? "" : mp[key][r].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
