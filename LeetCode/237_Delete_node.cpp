// https://leetcode.com/problems/delete-node-in-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 Since we couldn't enter the preceding node, we can not delete the given node. We can just copy the next node 
 to the given node and delete the next one.
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        // temp store the next node whih will be deleted
        // place temp value in node
        // place temp next in node next
        // delete temp
        ListNode* temp = node -> next;
        node -> val = temp -> val;
        node -> next = temp -> next;
        delete(temp);
    }
};
