// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
// https://www.geeksforgeeks.org/sort-linked-list-0s-1s-2s-changing-links/

/*
Iterate through the linked list. Maintain 3 pointers named zero, one and two to point to current ending nodes of
linked lists containing 0, 1, and 2 respectively. For every traversed node, we attach it to the end of its 
corresponding list. Finally, we link all three lists. To avoid many null checks, we use three dummy pointers 
zeroD, oneD and twoD that work as dummy headers of three lists.
*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // dummy nodes for making 3 lls of 0, 1, 2
        Node *zeroD = new Node(0);
        Node *oneD  = new Node(0);
        Node *twoD  = new Node(0);
        
        // pointers for dummy nodes
        Node *zero = zeroD;
        Node *one  = oneD;
        Node *two  = twoD;
        
        // run till head reach null
        // check the data in each node
        // push the node in dummy nodes accoriding to the data
        while (head){
            if (head -> data == 0){
                zero -> next = head;
                zero = zero -> next;
            }
            else if (head -> data == 1){
                one -> next = head;
                one = one -> next;
            }
            else if (head -> data == 2){
                two -> next = head;
                two = two -> next;
            }
            head = head -> next;
        }
        
        // joining all dummy nodes 
        // condition used in 1st eq as if oneD is null it wont have a next so will not be able to make ll
        zero -> next = (oneD -> next) ? oneD -> next : twoD -> next;
        one -> next = twoD -> next;
        two -> next = nullptr;
        
        // update head
        head = zeroD -> next;
        
        // remove dummy nodes from memory
        delete zeroD;
        delete oneD;
        delete twoD;
        
        return head;
    }
};
