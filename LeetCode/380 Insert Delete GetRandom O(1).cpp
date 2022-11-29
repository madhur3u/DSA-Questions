class RandomizedSet {
public:
    unordered_map<int, int> mp;             // map to store value -> index 
    vector<int> nums;                       // array to store all values

    RandomizedSet() { }
    
    bool insert(int val) {
        if (mp.count(val)) return false;    // if already present
        nums.emplace_back(val);             // place the val in end of nums array index -> nums.size() - 1
        mp[val] = nums.size() - 1;          // place index of val in nums in map, needed when we remove
        return true;
    }
    
    bool remove(int val) {
        if (!mp.count(val)) return false;   // if not present
        int index = mp[val];                // extract the index of value in nums using map
        int last = nums.back();             // extract the last element of nums
        mp[last] = mp[val];                 // change the index of last stored in mp to val's index
        nums[index] = last;                 // place the last element in the index of val

        // so what we have done is we swap the val with the last value of nums
        // also we swap the index aso in map, as we can delete the last el of nums in O(1)
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];  // get randomised value
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
