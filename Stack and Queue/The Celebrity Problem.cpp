/*
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

  0 1 2 3
0 0 1 1 1
1 1 0 1 0
2 0 0 0 0
3 1 1 1 0

in the above ex 2 (0 based index) is a celebrity since every one knows 2 elements in 2nd col are all 1 except for 2 himself
and 2 knows no one as elements in row 2 are all 0

first we put all person in a stack [ 0, 1, 2, 3 | our stack has all 4 persons (index)
now we run a loop till stack has at least 2 elements
pop 2 elements from stack, we will have 2 indices

person 1 = 3 (p1)
person 2 = 2 (p2)

now we will check in grid all combination
if (M[p1][p2] == 0 && M[p2][p1] == 0) // when both p1 and p2 dont know each other as m[3][2] = 0 ans m[2][3] = 0
first index tell us the person and second index tell us the other person sp p1 dont know p2 and vv
so we continue no need to add anyone to stack

if (M[p1][p2] == 0) means p1 dont know p2, so we are sure p2 cant be celebrity but unsure still about p1 
so push p1 in stack again,
else condition same but p2 pushed

when we areout of while loop we may have 1 or 0 el in stack, if st empty means no one is celebrity so return -1

if stack has element idx, this can be a celebrity
we check the row and col and this idx if its all row el are 0 and col el are 1 except when idx == i
return idx if above true else false
*/

class Solution {
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        
        // making stack and put everyone in stack
        stack<int> st;
        for (int i = 0; i < n; i++) st.push(i);
        
        // running loop till stack has at least 2 elements
        while (st.size() > 1) {
            
            // extract 2 elements
            int p1 = st.top(); st.pop();
            int p2 = st.top(); st.pop();
            
            // check all know not know conditions
            if (M[p1][p2] == 0 && M[p2][p1] == 0) continue;
            if (M[p1][p2] == 0) st.push(p1);
            else st.push(p2);
        }
        // if no one in stack -1
        if (st.empty()) return -1;
        
        // idx might be celebrity
        int idx = st.top();
        
        // check row and col in idx index
        for (int i = 0; i < n; i++) {
            if (idx == i || (M[idx][i] == 0 && M[i][idx] == 1)) 
                continue;
            else return -1;
        }
        return idx;
    }
};
