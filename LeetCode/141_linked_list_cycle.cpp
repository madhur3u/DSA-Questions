// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
brute force - push all nodes while traversing in hashmap/set and check if node was pushed previously or not

Floyd’s Cycle-Finding Algorithm // fast slow approach // 2 pointers // "tortoise and the hare algorithm"

Approach: This is the fastest method and has been described below:
Traverse linked list using two pointers.
Move one pointer(slow) by one and another pointer(fast) by two.
If these pointers meet at the same node then there is a loop. 
If pointers do not meet then linked list doesn’t have a loop.
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while (fast != nullptr && fast -> next != nullptr){
            
            slow = slow -> next;
            fast = fast -> next -> next;
            
            // At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if (slow == fast)
                return true;
        }
        return false;
    }
};
