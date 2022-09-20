// O(max(N,M))
// https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // make a dummy node ans, we will create or ans ll from this
        ListNode *ans = new ListNode(0);
        ListNode *head = ans;
        
        // for taking care od carry initially 0
        int carry = 0;
        
        // run till l1 or l2 any one has a element
        while (l1 || l2){
            
            // compute sum accordingly if l1, l2 exists, add carry
            // compute carry and sum % 10
            int sum = (l1 ? (l1 -> val) : 0) + (l2 ? (l2 -> val) : 0) + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            // add the sum as new node to ans
            ans -> next = new ListNode(sum);
            ans = ans -> next; 
            
            // shift l1 and l2 right if they exist
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }
        // if carry exist after doing above operation ex in case of 99 + 99
        // add new node to ans with data carry
        if (carry) ans -> next = new ListNode(carry);
        
        // return head of dummy node
        return head -> next;
    }
};
