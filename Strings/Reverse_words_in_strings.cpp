// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

class Solution
{
    public:
    // reverse the whole string
    // reverse each word after that
    string reverseWords(string s) 
    { 
        // whole string reverse n place
        reverse (s, 0, s.size() - 1);
        
        int i = 0, j = 0;
        
        // this will reverse each word
        while (j < s.size()){
            
            // word index will be given by i and j
            while (j < s.size() && s[j] != '.')
                j++;

            reverse (s, i, j - 1);
            j++;
            i = j;
        }
        return s;
    } 
    
    // function to reverse string from low to high
    void reverse (string &s, int lo, int hi){
        
        while (lo < hi){
            char temp = s[lo];
            s[lo++] = s[hi];
            s[hi--] = temp;
        }
    }
};
