/*
Two thing's Need to check :
-Frequency of Char need's to be same there both of string as we can do Transform every occurrence of 
 one existing character into another existing character
-All the unique char which there in String1 need's to there as well In string2

String 1 = "aabaacczp"                         String 2="bbzbbaacp"
Frequency in string1 :                         Frequency in string2 :
	    a->4                                                b->4
		b->1                                                a->2
		c->2                                                z->1
		z->1                                                c->1
		p->1                                                p->1
		
see in String 1 count array ->   1, 1, 1, 2, 4 =>sorted order
and in String 2 count array ->   1, 1, 1, 2, 4 =>sorted order

Unique all char   a,b,c,z,p  in string 1 is there as well in string2 so it's a valid One just return True
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if (word1.size() != word2.size()) return false;     // incorrect case string lengths diff

        int n = word1.size();
        vector<int> v1(26, 0), v2(26, 0);   // 2 freq vectors
        unordered_set<char> s1, s2;         // set to store unique elements

        // count freq in v1 and v2 and store unique elements in s1 and s2
        for (int i = 0; i < n; i++) {
            v1[word1[i] - 'a']++;
            s1.insert(word1[i]);
            v2[word2[i] - 'a']++;
            s2.insert(word2[i]);
        }
        // sort v1 and v2
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1 == v2 && s2 == s1;    // both freq vectors and both sets should be same for true
    }
};
