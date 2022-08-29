// https://practice.geeksforgeeks.org/problems/right-most-non-zero-digit1834/1#
// https://www.geeksforgeeks.org/right-most-non-zero-digit-in-multiplication-of-array-elements/
/*
1.  The question is too simple if you know basic maths. It is given that you have to find the rightmost positive digit.
  Now a digit is made multiple of 10 if there are 2 and 5. They produce a number with last digit 0.
2.  Now what we can do is divide each array element into its shortest divisible form by 5 and increase count of such occurrences.
3.  Now divide each array element into its shortest divisible form by 2 and decrease count of such occurrences.
  This way we are not considering the multiplication of 2 and a 5 in our multiplication.
4.  Set the multiplier value as either 1 or 5 in case count of 5 is not 0 after above two loops.
5.  Multiply each array variable now and store just last digit by taking remainder by 10
*/

import java.util.*;

class test
{
  public static int rightmostNonZeroDigit(int n, int[] a)     // function starts here
  {
    int count5 = 0;

    for (int i = 0; i < n; i++)                   // first we will find the count of 5 in array
    {                                             // we need to tke every element and check if it is divisible by 5
      while (a[i] > 0 && a[i] % 5 == 0)           // if it is then divide the element by 5 till it divides by 5
      {                                           // count5 will increment each time we divide a number by 5
        a[i] = a[i] / 5;
        count5++;
      }                                           // after coming out of this loop we have total no. of 5 in array

      if (a[i] == 0) return (-1);                 // this check for a[i] to be zero if it is our multiplication will always be 0
    }
    for (int i = 0; i < n; i++)
    {                                                     // now we are going to find no. of multiples of 2 in array
      while (count5 > 0 && a[i] > 0 && a[i] % 2 == 0)     // same logic divide a multipe of 2 till it divides
      {                                                   // here we will do count5--, because 2 * 5 makes 10
        a[i] = a[i] / 2;                                  // and we need to remove 10s from our array
        count5--;                                         // so when we find a 2 we decrease count5 as we have found a 10
      }                                                   // loop ends if count5 == 0 as all 5 are now over
    }                                                     // so we dont' need to remove 2 now as it will not make 10

    int m = 1;
    for (int i = 0; i < n; i++)                   // m stores multiplication of last digit only
    {                                             // we have removed all 10s so now our last digit will always be non zero
      m = ((m % 10) * (a[i] % 10)) % 10;          // so we only take last digit of m(previous ans) ans last digit of a[i]
    }                                             // and % 10 so we always store a single digit in m

    if (count5 != 0)                              // there might be a chance that no. of 2 were less than no. of 5
    {                                             // in that case we have to multiply by 5 our ans, as irrespective of no. of 5
      m = (m * 5) % 10;                           // last digit will always be 5, eg if count = 1 and count = 3
    }                                             // it will be 5 and 125 , so last digit is 5, %10 to store only last digit

    return m;                                     // m is the rightmost non zero digit
  }
  public static void main (String[] args) throws java.lang.Exception
  {
    Scanner scn = new Scanner(System.in);
    int N = scn.nextInt();                                  // input array and length
    int[] A = new int[N];

    for (int i = 0; i < N; i++)
      A[i] = scn.nextInt();

    System.out.println(rightmostNonZeroDigit(N, A));      // calling function and printing answer
    scn.close();
  }
}
