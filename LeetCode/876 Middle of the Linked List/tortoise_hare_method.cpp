// https://leetcode.com/problems/middle-of-the-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
In the Tortoise-Hare approach, we increment slow ptr by 1 and fast ptr by 2, so if take a close look fast ptr 
will travel double than that of the slow pointer. So when the fast ptr will be at the end of Linked List, 
slow ptr would have covered half of Linked List till then. So slow ptr will be pointing towards the middle of 
Linked List.

Approach: 

    1 Create two pointers slow and fast and initialize them to a head pointer.
    2 Move slow ptr by one step and simultaneously fast ptr by two steps until fast ptr is NULL or next of fast ptr is NULL.
    3 When the above condition is met, we can see that the slow ptr is pointing towards the middle of Linked List and hence 
      we can return the slow pointer.
*/


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        // two pointers slow and head
        ListNode* slow = head;
        ListNode* fast = head;
        
        // run till fast is null or the last element
        // odd even case both covered
        while (fast != nullptr && fast -> next != nullptr){
            
            slow = slow -> next;
            fast = (fast -> next) -> next;
        }
        
        // when fast has ended the traversal
        // slow will be at the middle of the ll so return slow
        return slow;
    }
};
