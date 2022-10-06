// https://www.geeksforgeeks.org/prefix-infix-conversion/

#include <bits/stdc++.h>
using namespace std;

// form the solution from end of string
// then it will be just like postfix to infix
string postfix_to_infix(string exp){

    int n = exp.size();
    stack <string> s;

    for (int i = n - 1; i >= 0; i-- ){

        // pushing operands when we have operand in exp[i] checking that in if condition
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')){

            string temp = "";
            temp.push_back(exp[i]);
            s.push(temp);
        }

        // if we find a operator we will make expression using the last 2 strings in stack
        // pop out the last 2 operands in stack and add the operator between them
        // push the resultant expression of these in stack again 
        // push s1 first than s2 so we dont need to reverse ans
        else {
            string s1 = s.top();
            s.pop();
            string s2 = s.top();
            s.pop();

            s.push("(" + s1 + exp[i] + s2 + ")");
        } 
    }
    return s.top();
}

int main() {
    cout << postfix_to_infix("*-A/BC-/AKL") << endl;
}
