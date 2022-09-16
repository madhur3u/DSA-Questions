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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // base case when head null means no el in list or when next el is null means this is last el
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        // new head will go to all the way to last, and will store last node which will now be new nead
        ListNode* newHead = reverseList(head -> next);
        
        // currently head will be 2nd last el when backtracing starts
        // so we make its next el and change pointer direction
        ListNode* next = head -> next;
        next -> next = head;
        head -> next = nullptr;
        
        return newHead;;
    }
};
