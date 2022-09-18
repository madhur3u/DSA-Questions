// https://leetcode.com/contest/biweekly-contest-87/problems/count-days-spent-together/
/*

    We just need to convert the given date to number in year.
    For example, "01-13" (13th January) represents 13th day in year, "02-13" (13th February) represents 44th day in year.
    This problem came in Biweekly Contest on 17th September, which is 260th day in year.


*/

class Solution {
public:
    
    // this function convert the mm-dd string to day in year ex 02-13 --> 44th day in year so --> 44
    int convertToDay(string s){
        
        // this array has no. of cumulative days, or prefix sum of days of month
        // this way we dont need to create an array to calculate day in year
        // first taken 0 as we are using month - 1 while calculating
        int cumulativeDays[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        
        // extracting month and day from string using ascii 
        int month = 10*(s[0] - '0') + (s[1] - '0');
        int day = 10*(s[3] - '0') + (s[4] - '0');
        
        // so day will be the no. of days in the current month + total no. of days of preceding months
        // eg. 05-15 --> day - 15, month - 5, so 15 (days in current month) + cumulativeDays[5 - 1] ==> 15 + 120(days from jan till april) ==> 135
        return day + cumulativeDays[month - 1];
    }
    
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        // convert the strings to day in year using the above function
        int alicearr = convertToDay(arriveAlice);
        int alicelev = convertToDay(leaveAlice);
        int bobarr = convertToDay(arriveBob);
        int boblev = convertToDay(leaveBob);
        
        // now we need to find diff of who left fisrt and who arrived 1st
        int ans = min(alicelev, boblev) - max(alicearr, bobarr) + 1;
        
        // ans will be neg when they were not together same time
        return max(0, ans);
    }
};
