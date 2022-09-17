// https://leetcode.com/problems/linked-list-cycle-ii/
// https://leetcode.com/problems/linked-list-cycle-ii/discuss/1701055/JavaC%2B%2BPython-best-explanation-ever-happen's-for-this-problem

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    // when we find meeting point we will make a pointer beg which will be at starting pos of list
    // and other pointer will be slow / fast which will be on the cycle
    // inc both pointer by 1 in each step, and at the point the collide
    // will be the starting point, see mathematical explanation from above link
    ListNode *startingPoint(ListNode *beg, ListNode *slow){
        
        while (beg != slow){
            beg = beg -> next;
            slow = slow -> next;
        }
        return slow;
    }
    
    // using tortoise-hare / Floyd Cycle Algorithm to find meeting pint if loop exist
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast -> next){
            
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if (slow == fast) return startingPoint(head, slow);
        }
        // no loop
        return nullptr;
    }
};
