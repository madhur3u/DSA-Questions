// Sweep-line Algorithm

class MyCalendarThree {
public:

    // keep values in sorted order using ordered map
    map<int, int> mp;
    MyCalendarThree() { }
    
    int book(int start, int end) {
        
        // inc the value for starting pos and dec for end
        mp[start]++;
        mp[end]--;

        int sum = 0, ans = 0;

        // compute sum from start and find max for each sum
        // the max sum will give us max intersection for all intervals in mp
        // store max sum in ans return ans 
        for (auto it : mp){
            sum = sum + it.second;
            ans = max(ans, sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

 /*
 
Approach 1: Sweep-line Algorithm
Intuition

 If we look at each time point separately, our task is to find out how many events are going on at this
 time point and find the time point of the max number of events. Every time we book a new event [start, 
 end), what we actually do is add 1 to the event counts to all time points in the range [start, end). The 
 final result of each book call is exactly the max count of a single time in the whole range of [1, 1e9).

For such kind of problem that increases all counts in some ranges by some constant values several times 
and asks to obtain all counts for those time points, we have a very classic solution called sweep-line 
algorithm: instead of keeping all values of counts in a traditional way, we use a differential array to 
represent the change that occurs at each time point. In this problem, we will increase the count by 1 at 
point start and decrease the count by 1 at point end. After enumerating all booked events and updating 
the differential array, we can simulate scanning the differential array with a vertical sweep-line from 
the origin time point 0 to the maximum 1e9 and obtain the prefix sum at each time point t, which is also 
the event count of time t. All we need to do now is find the maximum value of such counts when we scan 
the array.
Algorithm

    Initialize a HashMap diff as empty. We use a HashMap here instead of an array because the times given 
    by the inputs are sparse as there are at most 400 calls of book() function, we don't have to create 
    records for all numbers in [1, 1e9).
    Each time we book a new event [start, end)
        Update the diff[start] by adding 1 while diff[end] by subtracting 1.
        Initialize an integer cur = 0 to represent the number of intervals at the current time
        Enumerate all times that have records in diff in order, accumulate the corresponding value to 
        cur, and record the max value of cur during our enumeration, which is the result of book() call.

 */
