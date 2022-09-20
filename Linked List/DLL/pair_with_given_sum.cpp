// https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> ans;
        
        // find the pointer to the tail first
        Node *tail = head;
        while (tail -> next) tail = tail -> next;
        
        // while condition explanation
        // since head is left pointer and tail right
        // so in sorted array data of left always less than right, if not pointers have passed each other
        while (head -> data < tail -> data){
            
            // using same approach as if in sorted vector
            // find sum, comapare with target and move tail or head accordingly
            int sum = (head -> data) + (tail -> data);
            
            if (sum > target) tail = tail -> prev;
            else if (sum < target) head = head -> next;
            else{
                ans.push_back({head -> data, tail -> data});
                head = head -> next;
                tail = tail -> prev;
            }
        }
        return ans;
    }
};
