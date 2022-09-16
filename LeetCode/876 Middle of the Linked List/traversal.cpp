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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* curr = head;
        int count = 1;
        
        // first count the toatal elements in ll by traversing
        while (curr -> next != nullptr){
            curr = curr -> next;
            count++;
        }
        
        // now find mid point
        int mid = (count/2) + 1;
        curr = head;
        count = 1;
        
        // traverse till mid only
        while (count != mid){
            curr = curr -> next;
            count++;
        }
        // curr will have the md element so return that
        return curr;
    }
};
