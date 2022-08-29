// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
      
        // i is the pointer which points to the end point of our final array
        // j will traverse in whole array and place different elements in front
        int i = 0;
        
        for (int j = 1; j < a.size(); j++){
            
            // when we encounter same elements just j is increased and not i
            // and when we encounter diff element in both pointers
            // we first increase i so we can store that element in next pos and the current pos already has a unique no.
            // then we give val of 2nd pointer to the ++i position
            if (a[i] != a[j]) a[++i] = a[j];
        }
        return i+1;
    }
};

// {0,0,1,1,1,2,2,3,3,4}; original array
// 0 1 2 3 4 | 2 2 3 3 4  final array unique el till 4 and unchanged after that
// i points to 4 in this ex as we do not encunter any unique value after that
