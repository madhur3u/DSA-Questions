// https://leetcode.com/problems/find-duplicate-file-in-system/
/*
    We will use stringstream library of C++ to extract words from string.
    We will map the file content with directory and file name in unordered map.
    If there is one file for one file content, then it means that file is unique. We will not include that in our final answer.

    Consider the directory - "root/a 1.txt(abcd) 2.txt(efgh)". We have -

    Main Directory: root/a. All the characters that occur before the first space will constitute the main directory

    File Name: 1.txt. All the characters after space till the first opening bracket (() will constitite the file name inside the main directory.

    content: abcd. All the characters after the first opening bracket till closing bracket will constitute the file content of current file name.

Similarly, we can find the file 2.txt and its content efgh by parsing till the end of the string.

We can iterate through each element in paths and parse the path string using the above observation. To find the files having duplicate content, we can make use of a hashmap and map the content of a file with the file directory.

Atlast, we can iterate over the hashmap and if a particular content consists of multiple files, then push it into the ans vector, since we have found duplicate files having the same content.
*/

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        // this will store data / content as key
        // and filename with their root directory in value
        unordered_map <string, vector<string>> files;
        
        // iterate in paths vector
        for (auto path : paths){
            
            // get the first value before 1st space using string stream in root
            stringstream ss(path);
            string root;
            getline(ss, root, ' ');
            
            // values after 1st space are the file names and thier data
            // it can be > 1 so get that in s in while loop till ss has data
            string s;
            while (getline(ss, s, ' ')){
                
                // take out the file name which will be before first bracket, also add root and /
                // the data will be between the brackets
                string filename = root + '/' + s.substr(0, s.find('('));
                string data = s.substr(s.find('(') + 1,  s.find(')') - s.find('(') - 1);
                
                // push filename in data key
                files[data].push_back(filename);
            }
        }
        
        vector<vector<string>> ans;
        
        // iterate in map
        // if freq of values is > 1 means >1 files for same data
        // so push that vector stored in hashmap into ans
        for (auto file : files){
            if (file.second.size() > 1) ans.push_back(file.second);
        }
        return ans;
    }
};
