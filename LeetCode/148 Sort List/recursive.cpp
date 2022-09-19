// https://leetcode.com/problems/sort-list/
// memory leakage might be there, to get that correct make prev for l1 l2 in merge and point them to null after merging
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
    
    // we will dort the list using merge sort 
    ListNode* sortList(ListNode* head) {
        
        // base case when no or one element
        if (!head || !head -> next)
            return head;
        
        // Using 2pointer / fast-slow pointer find the middle node of the list.
        // first middle in case of even
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast -> next && fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // now we need two pointers pointing at two halves
        // first will be head at starting
        // we make fast as 2nd at slow -> next i.e. mid or just after mid in case of odd
        // slow -> next = nullptr; to seprate the ll into two
        fast = slow ->next;
        slow -> next = nullptr;
        
        // call the sortList function for both halves, and merge them
        ListNode *newHead = merge(sortList(head), sortList(fast));
        return newHead;
    }
    
    // merging two lls O(log n) extra space is used in recursion
    ListNode* merge(ListNode* l1, ListNode* l2) {
        
        // making a new ll to store merged ll
        // curr pointer will make the new ll
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        // traverse till any one of the ll is empty
        while (l1 && l2){
            
            // when l1 < l2, add l1 to curr, shift l1 right
            if (l1 -> val <= l2 -> val){
                curr -> next = l1;
                l1 = l1 -> next;
            }
            // add l2 to curr, shift l2 to right
            else {
                curr -> next = l2;
                l2 = l2 -> next;
            }
            // inc current pointer also, shift right
            curr = curr -> next;
        }
        // if elements left in any of the ll
        // push the whole ll from l1 or l2 pos to curr
        if (l1)
            curr -> next = l1;
        if (l2)
            curr -> next = l2;
        
        // return head
        return dummy -> next;
    }
};
