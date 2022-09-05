// https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1
// https://www.geeksforgeeks.org/smallest-sum-contiguous-subarray/

// same as max subarray sum, KADANE'S ALGO
// but instead of computing max sum we will check for min sum
// and if sum > 0 make it zero again as that will inc our sum if +ve

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      
      // variables which hold current subarray sun and ans
      int current_sum = 0;
      int min_sum = INT_MAX;
      
      for (int i : a){
          
          // if the sum is +ve then make it zero
          // as if we want sum to be min +ve value will be of no use
          if (current_sum > 0) current_sum = 0;
          
          // add current element to sum
          // compare with min sum so far
          current_sum += i;
          min_sum = min(min_sum, current_sum);
      }
      return min_sum;
  }
};
