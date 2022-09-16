// https://leetcode.com/problems/reverse-linked-list/

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

// 3 pointers approach
// make a prev node which hold value before head node
// make one next node which haev value of node next to head node
// iterate from head, shift pointer of head from next to prev
// shift prev and head forwards, finally we will have head at null and prev will be at new head position last

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = nullptr;
        
        while (head){
            ListNode* next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
