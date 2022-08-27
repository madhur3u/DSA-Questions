#include <iostream>

using namespace std;

void swapNo(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}// function to swap two elemets of array pointers passed

void reverseArray(int arr[], int fi, int li){

    if (fi<li){
        swapNo(&arr[fi], &arr[li]);
        reverseArray(arr, fi+1, li-1);
    }// approach is same as normal reverse increase the low index and dec the high index
}// fi - first index, li- last index

int main()
{   
    int arr[8] = {1,2,3,4,5,6,7,8};
    reverseArray(arr, 0, 7);

    for (int i : arr) cout << i << endl;
}
