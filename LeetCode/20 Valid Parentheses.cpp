class Solution {
public:
    bool isValid(string s) {
        stack<char> br;

        for (auto ch : s){
            // if open brackets push in stack
            if (ch == '(' || ch == '[' || ch =='{') br.emplace(ch);

            // 1st st is not executed ans br is empty means ch will be a closed bracket
            // since stack empty it cannot be a valid case so return false
            else if (br.empty()) return false;

            // case for all 3 closed bracket when stack not empty
            // if matching bracket found pop and continue else return false
            else if (ch == ')'){
                if (br.top() == '(') br.pop();
                else return false;
            }
            else if (ch == ']'){
                if (br.top() == '[') br.pop();
                else return false;
            } 
            else if (ch == '}'){
                if (br.top() == '{') br.pop();
                else return false;
            }
        }
        // for case like '[' br might not be empty so check that and return
        return (br.empty()) ? true : false;
    }
};
