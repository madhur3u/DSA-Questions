// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        
        // if empty list
        if (head == nullptr) return head;
        
        // CASE 1 when head has to be deleted
        // loop till head is not val and update head
        while (head != nullptr && head -> val == val)
            head = head -> next;
        
        // make 2 pointers for prev and curr nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        // traverse in linked list till its null
        while (curr != nullptr){
            
            // when we found a node with val
            // prev will get the curr next address
            // curr will be equal to its next
            if (curr -> val == val){
                prev -> next = curr -> next;
                curr = curr -> next;
            } 
            
            // assign curr to prev and curr++ by pointing to next
            else {
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;
    }
};
