// https://www.geeksforgeeks.org/generate-binary-strings-without-consecutive-1s/?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=generate-binary-strings-without-consecutive-1s

#include <bits/stdc++.h>
using namespace std;

void generate_string(char str[], int n, int k){

    // base case when n == k means our string is formed
    // terminate string and print it
    if (n == k) {
        str[k] = '\0';
        cout << str << endl;
        return;
    }

    // case when either k == 0, means this is the first value in string or previous char was 0
    // in both cases we can add 0 or 1 to the next pos, so adding and calling fn again 
    if (k == 0 || str[k - 1] == '0') {

        str[k] = '0';
        generate_string(str, n, k + 1);

        str[k] = '1';
        generate_string(str, n, k + 1);
    }

    // when previous char was 1, next can only be zero
    else {
        str[k] = '0';
        generate_string(str, n, k + 1);
    }
}

int main(){
    int n = 6;
    char str[n];
    generate_string(str, n, 0);

    return 0;
} 
