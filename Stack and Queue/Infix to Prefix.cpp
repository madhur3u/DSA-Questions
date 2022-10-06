// https://takeuforward.org/data-structure/infix-to-prefix/
// https://www.geeksforgeeks.org/convert-infix-prefix-notation/

#include <bits/stdc++.h>
using namespace std;

int precedence(char ch){
    switch (ch) {
        case '^' : return 3;
        case '*' : return 2;
        case '/' : return 2;
        case '+' : return 1;
        case '-' : return 1;
    }
    return 0; // for '(' case least precedence so it is not popped before ')'
}

string infixToPostfix(string s) {
    
    // op will hold the operators in stack according to thier precedence
    // ans will have the postfix expression
    stack<char> op;
    string ans = "";
    
    for (char ch : s){
        
        // if it is a operand directly push in the ans
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            ans.push_back(ch);
            
        // when we have open bracket push in stack
        else if (ch == '(') op.push(ch);
        
        // when found closed brackets, run through stack till we find closed bracket
        // push each operator we go through in ans till we reachopen bracket
        // pop the open bracket after while loop ends, we do not include brackets in our ans 
        else if (ch == ')'){
            while (op.top() != '('){
                ans.push_back(op.top());
                op.pop();
            }
            op.pop();
        }
// ----------------------------------------------------------------------------------------------------
        // CHANGE IN POSTFIX ALGO HERE
        // for prefix code we will have 2 conditions
        // when we found a operator we push it in stack according to its precedence
        // if the already pushed op has >= precedence than ch
        // than we push it in ans and pop it till we empty stack or find a op with lesser prec than ch
        // push the operator to op when we have dealt with precedence
        // in case when we encounter '(' in op.top(), since it pr is 0 so while loop won't run for that
        else if (ch == '^') {
            while (!op.empty() && precedence(op.top()) >= precedence(ch)){
                ans.push_back(op.top());
                op.pop();
            }
            op.push(ch);
        }
        else {
            while (!op.empty() && precedence(op.top()) > precedence(ch)){
                ans.push_back(op.top());
                op.pop();
            }
            op.push(ch);
        }
    }
    // when we get out of for loop there will be some operators which are not pushed
    // so we push them as they are in stack
    while (!op.empty()){
        ans.push_back(op.top());
        op.pop();
    }
    return ans;
}

// reverse string
// change brackets orientation after reversing
// send to postfix exp maker fn
// Note that for Step 2, we don’t use the postfix algorithm as it is.
// There is a minor change in the algorithm.
// reverse ans and return that
string infixToPrefix(string infix) {

    reverse(begin(infix), end(infix));

    for (int i = 0; i < infix.size(); i++){

        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    string prefix = infixToPostfix(infix);
    reverse(begin(prefix), end(prefix));
    return prefix;
}

int main() {
    cout << infixToPrefix("x+y*z/w+u^k^l") << endl;
}
