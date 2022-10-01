// https://practice.geeksforgeeks.org/problems/power-set4302/1
// https://leetcode.com/problems/subsets/solutions/1766969/c-100-faster-solution-0-ms-bit-manipulation-easy-to-understand/?orderBy=most_votes

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    
		    vector<string> res;
		    int n = s.size();
		    
		    // there will be toatl 2 ** n subsets so running first loop till that
		    // shifting 1 n times will give us 2**n
		    for (int i = 1; i < (1<<n); i++){
		        
		        // ans will hold a single subset
		        // j will tell us index of character to be added from string s
		        // temp will hold the current number in i as we wont change i directly
		        string ans = "";
		        int temp = i, j = 0;
		        
		        // run till temp > 0
		        while (temp > 0){
		            
		            // if the and of temp and 1 is true push char at j to ans
		            // inc j, and remove the rightmost bit from temp
		            if (temp & 1) ans.push_back(s[j]);
		            j++;
		            temp = temp >> 1;
		        }
		        // push the ans formed to res
		        res.push_back(ans);
		    }
		    // sort res and return
		    sort(begin(res), end(res));
		    return res;
		}
};
