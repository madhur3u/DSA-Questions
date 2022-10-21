/*
Intuition: Sort the array and store the rank of the element in a map.

Approach:

    Copy all the elements of the array in a dummy array.
    Sort the dummy array.
    Take a variable temp to calculate the rank of each element.Initially the value of temp is 1.
    Maintain a map to store the rank of each element.
    Now traverse through the dummy array,if element is previously not stored in map then store the value of element with the temp and then increament temp.
    Now traverse through the original array and print the rank of that corresponding element using map.
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> b(arr);
        unordered_map <int, int> rank;
        sort(b.begin(), b.end());

        int currRank = 1;
        for (int i = 0; i < b.size(); i++) 
            if (rank.find(b[i]) == rank.end()) rank[b[i]] = currRank++;
        
        for (int i = 0; i < arr.size(); i++)
            arr[i] = rank[arr[i]];
        
        return arr;
    }
};
