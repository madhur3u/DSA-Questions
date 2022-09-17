// https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/1164537/Short-and-Simple-One-Pass-Solution-w-Explanation-or-Beats-100-or-No-dummy-node-required!

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // make 2 pointers static and moving
        ListNode* stat = head;
        ListNode* move = head;
        
        // shift the move pointer n nodes ahead and static will be at head
        while (n--) move = move -> next;
        
        // if move reached null means we have to remove 1st element
        // so change head to its next and return
        if (move == nullptr) {
            head = stat -> next;
            delete(stat);
            return head;
        }
        
        // when move not null, start moving both pointers now stat and move
        // traverse till move reach last node
        while (move -> next){
            stat = stat -> next;
            move = move -> next;
        }
        
        // now after this the node to be removed will be the one after stat
        // so remove that and return head
        stat -> next = stat -> next -> next;
        return head;
    }
};

/*
✔️ Solution (Two-Pointer, One-Pass)

We are required to remove the nth node from the end of list. For this, we need to traverse N - n nodes from the start of the list, 
where N is the length of linked list. We can do this in one-pass as follows -

    Let's assign two pointers - fast and slow to head. We will first iterate for n nodes from start using the fast pointer.

    Now, between the fast and slow pointers, there is a gap of n nodes. Now, just Iterate and increment both the pointers till 
    fast reaches the last node. The gap between fast and slow is still of n nodes, meaning that slow is nth node from the last node 
    
    (which currently is fast).

For eg. let the list be 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9, and n = 4.

1. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> null
   ^slow               ^fast
   |<--gap of n nodes-->|
 
 => Now traverse till fast reaches end
 
 2. 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> null
                        ^slow               ^fast
                        |<--gap of n nodes-->|
						
'slow' is at (n+1)th node from end.
So just delete nth node from end by assigning slow -> next as slow -> next -> next (which would remove nth node from end of list).

    Since we have to delete the nth node from end of list (And not nth from the last of list!), we just delete the next node to slow pointer and return the head.

*/
