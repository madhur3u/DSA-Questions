// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
We can solve this problem with two pointer approach: idea is to make two pointers - 
fast pointer(jumps two node) and slow pointer(jumps one node). 
And when fast pointer reaches end, slow pointer would have reached middle element.

also make one more el prev which will point to one node behind slow node, 
so that we can delete slow node and refrence prev to slow's next
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        // when only one element in list
        if (head -> next == nullptr) {
            head = nullptr;
            return head;
        }
        
        // make 3 pointers, slow and fast to find the mid element using tortoise hare method
        // prev node will point to one behind middle element
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        // tortoise hare method to find mid element
        while(fast && fast -> next){
            
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // deleting mid node
        prev -> next = slow -> next;
        delete(slow);
        
        return head;
    }
};
