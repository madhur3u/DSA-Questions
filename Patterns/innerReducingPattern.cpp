// https://www.geeksforgeeks.org/inner-reducing-pattern-printing/

#include<iostream>
using namespace std;

/*
5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5
*/

int main(){

    int n = 5;
    int val;

    for (int i = 1; i <= 2*n-1; i++){
        val = n;

        for (int j = 1; j<=2*n-1; j++){

            std::cout<<val<<" ";

            // changing value for first half
            // analayze the i+j for the change in values
            if (i <= n){
                if (i+j < 2*i) val--;
                else if (i+j>=2*n) val++;
            }
            // 2nd half
            else {
                if (i+j < 2*n) val--;
                else if (i+j>=2*i) val++;
            }
        }
        std::cout<<endl;
    }              
    return 0;
}
