//https://www.pepcoding.com/resources/online-java-foundation/patterns/design-pattern-18-official/ojquestion

/*
*	*	*	*	*	*	*	0
	*				*	  1
		*		*	    2 
			*	      3
		*	*	*     4	
	*	*	*	*	*   5	
*	*	*	*	*	*	* 6	
*/

#include <iostream>
using namespace std;
int main(int agrc, char**argv){
    int n;
    cin >> n;                   // number of rows

    //write your code here
    
    for (int i=0; i<n; i++){          // loop1  
        for (int j = 0; j<n; j++){    // loop 2 loops create n x n square
            
            if (i == 0 || i == n-1)                         // this prints 1st and last row all stars 
                cout<<"*";
                
            else if (i==j || i+j == n - 1)                  // this prints all diagonal stars making a empty hourglass                
                cout<<"*";
                
            if (i>n/2 && i+j>n-1 && i+j<2*i && i != n-1)    //   
                cout<<"*";
            
            cout<<"\t";
            
        }
        cout<<endl;
    }
    
}
