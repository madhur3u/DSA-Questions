// https://leetcode.com/problems/odd-even-linked-list/
// https://leetcode.com/problems/odd-even-linked-list/discuss/1607746/C%2B%2B-Simple-Solution-w-Images-and-Explanation-or-Brute-Force-%2B-O(1)-In-place-Transformation

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

/*

    The idea is to split the linked list into 2 : one containing all odd nodes and other containing all even
    nodes. And finally, attach the even node linked list at the end of the odd node linked list.
    To split the linked list into even nodes & odd nodes, we traverse the linked list and keep connecting the
    consecutive odd nodes and even nodes (to maintain the order of nodes) and save the pointer to the first even node.
    Finally, we insert all the even nodes at the end of the odd node list.

*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        // all boundary cases, as till length 2 no need to seprate odd even
        if (!head || !head->next || !head->next->next) return head;
        
        // make two pointers for odd and even place 
        // one even Head to connect the even link list with odd
        // we will create 2 link list using odd and even and join them
        ListNode *odd = head;
        ListNode *even = head -> next;
        ListNode *evenHead = even;
        
        // run loop till end node is reached
        // using next.next we we will seprate all odd and even nodes
        while (odd -> next && even -> next){
            
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;
            odd = odd -> next;
            even = even -> next;
        }
        
        // join odd node with the head of even linklist saved before
        odd -> next = evenHead;
        return head;
    }
};
