/*
PRINT THE PATTERN BELOW
*                 *   1
* *             * *   2
* * *         * * *   3
* * * *     * * * *   4
* * * * * * * * * *   5
* * * *     * * * *   6
* * *         * * *   7
* *             * *   8
*                 *   9
*/

#include<iostream>
using namespace std;

int main(){

    int n = 5;
    int st = 1, sp = 2*n-2;                 // initial values of stars and spaces

    for (int i = 1; i<2*n; i++){

        // initial stars
        for (int j = 1; j <= st; j++){
            cout<<"* ";
        }
        // spaces
        for (int j = 1; j <= sp; j++){
            cout<<"  ";
        }
        // last stars
        for (int j = 1; j <= st; j++){
            cout<<"* ";
        }

        // st and space decrease after half printed
        if (i<n){
            st++;
            sp-=2;
        }
        else{
            st--;
            sp+=2;
        }
        cout<<endl;
    }
    return 0;
}