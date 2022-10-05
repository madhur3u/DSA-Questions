// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
// https://takeuforward.org/data-structure/infix-to-postfix/
// READ ABOVE ARTICLE TO UNDERSTAND BETTER

class Solution {
  public:
    // this fn tells precedence of a operator using switch case
    int precedence(char ch){
        switch (ch) {
            case '^' : return 3;
            case '*' : return 2;
            case '/' : return 2;
            case '+' : return 1;
            case '-' : return 1;
        }
        return 0; // for '(' case lease precedence so it is not popped before ')'
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
            
            // when we found a operator we push it in stack according to its precedence
            // if the already pushed op has >= precedence than ch
            // than we push it in ans and pop it till we empty stack or find a op with lesser prec than ch
            // push the operator to op when we have dealt with precedence
            // in case when we encounter '(' in op.top(), since it pr is 0 so while loop won't run for that
            else {
                while (!op.empty() && precedence(op.top()) >= precedence(ch)){
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
};
