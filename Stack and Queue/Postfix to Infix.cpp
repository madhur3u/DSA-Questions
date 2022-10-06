// https://www.geeksforgeeks.org/infix-to-postfix-using-different-precedence-values-for-in-stack-and-out-stack/?ref=rp

/*
Algorithm 
1.While there are input symbol left 
…1.1 Read the next symbol from the input. 
2.If the symbol is an operand 
…2.1 Push it onto the stack. 
3.Otherwise, 
…3.1 the symbol is an operator. 
…3.2 Pop the top 2 values from the stack. 
…3.3 Put the operator, with the values as arguments and form a string. 
…3.4 Push the resulted string back to stack. 
4.If there is only one value in the stack 
…4.1 That value in the stack is the desired infix string. 
*/

#include <bits/stdc++.h>
using namespace std;

string postfix_to_infix(string exp){

    stack <string> s;

    for (char ch : exp){

        // pushing operands when we have operand in ch checking that in if condition
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){

            string temp = "";
            temp.push_back(ch);
            s.push(temp);
        }

        // if we find a operator we will make expression using the last 2 strings in stack
        // pop out the last 2 operands in stack and add the operator between them
        // push the resultant expression of these in stack again 
        else {
            string s1 = s.top();
            s.pop();
            string s2 = s.top();
            s.pop();

            s.push("(" + s2 + ch + s1 + ")");
        } 
    }
    return s.top();
}

int main() {
    cout << postfix_to_infix("abc*+de/fg*h*+-") << endl;
    cout << postfix_to_infix("abc*h/+");
}
