// https://leetcode.com/problems/copy-list-with-random-pointer/
// https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/
/*
The algorithm is composed of the follow three steps which are also 3 iteration rounds.

    Iterate the original list and duplicate each node. The duplicate
    of each node follows its original immediately.
    Iterate the new list and assign the random pointer for each
    duplicated node.
    Restore the original list and extract the duplicated nodes.

STEP 1: PASS 1 (Altering the link list)
Iterate the given link list and at each iteration create a copy (except random pointer) of each node and 
insert it just next to the node it's copied from as shown below.

    If initially the link list is like : A->B->C->D
    Then after this step the link list will be : A->A'->B->B'->C->C'->D->D'
    where A',B',C',D' nodes are the copy of A,B,C,D nodes respectively except the random pointers.

STEP 2: PASS 2 (Copying the random pointers)
Again iterate the link list and alternatively copy the old node's random pointer (if exists) to the new 
node's random pointer as shown below node->next->random=node->random->next.

STEP 3 : (PASS 3) (Restoring the old link list).
Extract the new ll using temp node and old ll using curr node.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // if no ll
        if (!head) return nullptr;
        
        // STEP ! : inserting new nodes b/w old
        // curr will traverse old ll and temp will have new nodes
        // link the new nodes with old nodes such that they are b/w them
        Node *curr = head;
        Node *temp;
        
        while (curr){
            temp = new Node(curr -> val);
            temp -> next = curr -> next;
            curr -> next = temp;
            curr = curr -> next -> next;
        }
        
        // STEP 2: random poiters
        // take 2 nodes n a iteration ex. A and A'
        // place random pointer of new node with old node's random next if exist
        curr = head;
        
        while (curr){
            if (curr -> random) curr -> next -> random = curr -> random -> next;
            curr = curr -> next -> next;
        }
        
        // STEP 3 : extracting both new and old nodes
        // extract new node with temp and ol with curr
        // place new head in a new node
        curr = head;
        temp = curr -> next;
        Node *newhead = temp;
        
        while (temp){
            curr -> next = curr -> next -> next;
            if (temp -> next) temp -> next = temp -> next -> next;
            
            curr = curr -> next;
            temp = temp -> next;
        }
        return newhead;
    }
};
