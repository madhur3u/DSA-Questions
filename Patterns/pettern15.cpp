// https://www.pepcoding.com/resources/online-java-foundation/patterns/design-pattern-15-official/ojquestion

/* n = 7
			1				
		2	3	2			
	3	4	5	4	3		
4	5	6	7	6	5	4	
	3	4	5	4	3		
		2	3	2			
			1			
*/


#include <iostream>
using namespace std;
int main(int argc, char**argv){
        int n;
        cin >> n;
    
        int sp = n/2; // space in front of every line for 1st it is n/2
        int st = 1;   // st are the numbers in each line for 1st line always 1 number
        
        int x;        // x will be the variable we will print and change throughout our program
        
        for (int i = 0; i<n ; i++){               // external loop control no. of rows = n
            
            if (i <= n/2 ) x = i + 1;             // first value of x in each row depends on value of i or row number 
            else x = n - i;
            
            for (int j = 0; j<sp; j++){           // print spaces
                cout<<"\t";
            }
            for (int j = 0; j<st; j++){           // print pattern and change value of x accordingly
                if (j<st/2) cout <<x++<<"\t";
                else cout <<x--<<"\t";
            }
            for (int j = 0; j<sp; j++){           // print spaces
                cout<<"\t";
            }
            
            if (i<n/2){                           // the no. of time sp and st loop runs depends on value of sp and st
                st+=2;                            // so we have to change value of sp and st accordingly for each row
                sp--;
            }
            else{
                st-=2;
                sp++;
            }
            
            cout<<endl;                           
        }
}
