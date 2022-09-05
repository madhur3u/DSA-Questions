// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

/*
If we think carefully, we want to compare the elements on the right side only. 
So, what if we start from the last element.
That is, we’ll try to remember the greatest element encountered so far and we’ll use that to decide whether a candidate is a leader or not.
First, we’ll start the traversal from right. 
Then, we move towards the left. Whenever we encounter a new element, we check with the greatest element obtained so far.
If the current element is greater than the greatest so far, then the current element is one of the leaders and we update the greatest element.
Else, we proceed with the further elements on the left. This method prints the leaders in reverse direction of their occurences. 
If we are concerned about the order, we can use an extra array or a string to order.
*/

class Solution{
    public:
    vector<int> leaders(int a[], int n){
        
        // theis vector will have all the leaders and leader will have leader so far when traverse from right hand side
        vector<int> ans;
        int leader = 0;
        
        // traverse in loop in reverse order
        // if find diff max el push it in ans
        for (int i=n-1; i>=0; i--){
            
            if (a[i] >= leader){
                ans.push_back(a[i]);
                leader = a[i];
            }    
        }
        
        // above approach will give us our leader array in reverse order
        // so wereverse the ans array to get the result we want
        int low = 0, high = ans.size()-1;
        while (low < high){
            int temp = ans[low];
            ans[low] = ans[high];
            ans[high] = temp;
            
            low++;
            high--;
        }
        return ans;
    }
};
