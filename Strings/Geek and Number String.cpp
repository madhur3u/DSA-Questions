// https://practice.geeksforgeeks.org/problems/904237fa926d79126d42c437802b04287ea9d1c8/1
/*
Traverse all the elements of string. If the stack is empty then just push the element into stack. 
When the stack is not empty create an empty string and form a string of with the top character of the stack 
and with the current index element. If the string is found in the list of the given elements then pop the 
top element otherwise push the element into stack.

Return the stack size as it will be the minimised size of the string.
*/

class Solution{
public:
    int minLength(string s, int n) {
        
        // make set with all popable pairs so finding while traversing is O(1)
        unordered_set<string> check = {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"};
        
        stack<char> st;
        
        // traverse the string
        for (char ch : s){
            
            // make string of ch else we will get error char cannot be mapped with string
            // so we will have current character in curr
            string curr = "";
            curr = curr + ch;
            
            // checking if pair is formed
            // if the string formed by the curr element and element of top of stack is in check set
            // then pair is formed and we will pop the top element of stack
            if (!st.empty() && check.find(curr + st.top()) != check.end()){
                st.pop();
            }
            // if pair not formed, push the curr element ch to stack
            else {
                st.push(ch);
            }
        }
        return st.size();
    } 
};
