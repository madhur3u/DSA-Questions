// https://leetcode.com/problems/the-skyline-problem/solutions/2094329/c-easiest-explanation-ever-guaranteed-beginner-friendly-detailed-o-nlogn/?orderBy=most_votes

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int,int>> coord;

        // we will store heights in multiset as it is sorted 
        // and can remove/insert any element in logN time
        multiset<int> pq{0};
        vector<vector<int>> ans;

        // push the starting corrdinate with negetive height (-ve denote start of rectangle)
        // push the end coordinate with +ve height
        for (auto i : buildings){
            coord.push_back({i[0], -i[2]});
            coord.push_back({i[1], i[2]});
        }

        // sort the coordinates set initial height as 0
        sort(coord.begin(), coord.end());
        int height = 0;

        // iterate in coordinates
        for (auto point : coord){
            
            // take out the current point and height at current point
            int currentpoint = point.first;
            int currentheight = point.second;

            // if the height is les than 0 means stating point of that rectangle
            // push it into our multiset pq
            // if +ve means we are leaving that rectangle so delete that height from pq
            if (currentheight < 0)
                pq.insert(-currentheight);
            else
                pq.erase(pq.find(currentheight));

            // get the current max element in multiset
            // if the height is not equal to top, means we have either entered a new rectangle or left one
            // in any case update height and push coordinated to ans, point and height
            int pqtop = *pq.rbegin();
            if (height != pqtop){
                height = pqtop;
                ans.push_back({currentpoint, height});
            }
        }
        return ans;
    }
};
