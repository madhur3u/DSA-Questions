class MyCalendar {
public:
    set <pair<int, int>> bookings;
    MyCalendar() { }
    
    bool book(int start, int end) {

        // find the lower bound od the given slot <start, end> in set
        // it will give us the interval if slot present 
        // In case k is not present in the set container, the function returns an iterator 
        // pointing to the immediate next element which is just greater than k.
        auto next_slot = bookings.lower_bound({start, end});
        
        // first condition checking the slot end with first value at next_slot
        // in case [3,10] , [15,20] if slot is -> [11,16] end = 16
        // then next points to [15, 20] and 16 > 15 as it coincide with next slot
        // so we return false
        // this condition wont run if next is out of set means prev smaller slot was last one
        if (next_slot != bookings.end() && next_slot -> first < end){
            return false;
        }
        // checking for previous slot if prev condition true
        // this wont run if next slot was at beginning of set
        // ex. [3,10] , [15,20] slot is [7, 14]
        // for given slot 14 !> 15 se prev condition wont run
        // now in [3,10](prev) since 10 > 7 (prev_slot -> second > start) so it coincide hence we return false
        else if (next_slot != bookings.begin()) {
            auto prev_slot = prev(next_slot);
            if (prev_slot -> second > start)
                return false;
        }
        // if both above cond do not execyte means interval do not coincide
        // so push in set and return true
        bookings.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
