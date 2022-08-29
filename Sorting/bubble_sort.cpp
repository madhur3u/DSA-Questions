// https://www.geeksforgeeks.org/bubble-sort/

#include <iostream>
using namespace std;

// this function will swap two variables
void swap(int *a, int *b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	// your code goes here
	cout << "Bubble Sort" << endl;

	// array to sort and its length in n
	int a[5] = {8,5,7,2,1};
	int n = 5;

	// in bubble sort we compare two adjacent elements
	// and swap them if they are not sorted
	// in 1st loop we have no. of passes
	// in each pass one element will always be in sorted position 
	// that will be our last element
	// the inner loop only runs till n - i - 1 as nth element is sorted after each pass
	// in bubbles sort the array is sorted from last means the max el will be places at last pos in 1st iteration
	// 2nd it - 2nd max at 2nd last and so on
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){

			// sorting 
			// ig two elements are not sorted swap them
			if (a[j] > a[j+1])
				swap(&a[j], &a[j+1]);
		}
	}
	
	// printing
	for (int i = 0; i < n; i++)
	cout<<a[i]<<endl;
}
