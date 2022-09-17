// https://leetcode.com/problems/palindrome-linked-list/

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
    
    // function to reverse a list when head is given
    ListNode* reverseList(ListNode* head){

        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        while (head){
            next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        // finding mid 
        // this will give us first mid in even list and mid in odd list
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast -> next && fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // now we need to reverse nodes after slow pointer
        slow -> next = reverseList(slow -> next);
        
        // so now we have list in 2 parts, if palindrome then 1st and 2nd list el should be same
        // so make 2 pointers one at start and one after mid (slow->next)
        // traverse and check if values equal till node null
        // in case of odd the mid element will not be checked and only elements around it are checked
        // insted of using ptr12, head and slow pointers could have been used
        ListNode* ptr1 = head;
        ListNode* ptr2 = slow -> next;
        
        while (ptr2){
            if (ptr1 -> val != ptr2 -> val) return false;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return true;
    }
};
