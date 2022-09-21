// https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (k == 1) return head;
        
        // finding length of ll
        ListNode *curr = head;
        int len = 1;
        while (curr -> next) curr = curr -> next, len++;
        
        // curr and forward will traverse in the linked list
        curr = head;
        ListNode *forw;;
        
        // making variable for temp head and tail to reverse ll
        // we will store our block in thead and ttail
        // and join with the previous block after for statement ends
        ListNode *thead = nullptr, *ttail = nullptr, *tail = nullptr;
        
        // if len < k we do not need to reverse block
        while (len >= k){
            
            // running for loop k times to get a block and reverse it
            for (int i = 0; i<k; i++){
                
                // set forward ahead current
                // break current from ll
                forw = curr -> next;
                curr -> next = nullptr;
                
                // if 1st element of block both head and tail at same point
                if (!thead) {
                    ttail = curr;
                    thead = curr;
                }
                // if not 1st element, link current with the previous head
                // after that update new head
                else {
                    curr -> next = thead;
                    thead = curr;
                }
                // update curr for next element
                curr = forw;
            }
            
            // when we come out of above loop in thead and ttail we will have reversed block
            // if this was first block then tail bill be null
            // set original head as thead nad tail to ttail
            if (!tail){
                tail = ttail;
                head = thead;
            }
            // from 2nd block onwards
            // join original tail with thead, update original tail
            else {
                tail -> next = thead;
                tail = ttail;
            }
            // set both temp pointers to null again and update length
            ttail = nullptr;
            thead = nullptr;
            len = len - k;
        }
        // in any case when while loop ends update tail's next to current
        // if elements left curr points to the 1st element else it points to null
        tail -> next = curr;
        
        // head was updated return that
        return head;
    }
};
