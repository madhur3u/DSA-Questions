// https://www.pepcoding.com/resources/online-java-foundation/patterns/design-pattern-16-official/ojquestion

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cout<<"Enter number of rows"<<endl;
    cin>>n;
    int N = 2*n - 1;  //width
    
    for(int j = 0; j<n; j++){         // this loop controls height of pattern
        
        int x = 1;                    // this variable control the print inside
        for(int i = 0; i<N; i++){     // controls width 
            
            if(i<N/2){                // for increasing number
                if(x<=j+1) cout<<x;   // checking till where we need to print
                x++;
            }
            else if(i==N/2){          // for middle number which has to be printed only once
                if(x<=j+1) cout<<x;
                x--;                  // decreasing for other half
            }
            else{
                if(x<=j+1) cout<<x;   // check and print in decreasing order
                x--;
            }
            cout<<"\t";               // tab sapce to be printed
        }
        cout<<endl;
    }
}

/*
1												1	
1	2										2	1	
1	2	3								3	2	1	
1	2	3	4						4	3	2	1	
1	2	3	4	5				5	4	3	2	1	
1	2	3	4	5	6		6	5	4	3	2	1	
1	2	3	4	5	6	7	6	5	4	3	2	1	
*/
