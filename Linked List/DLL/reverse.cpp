// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

Node* reverseDLL(Node * head)
{
    // when only 1 element in dll or no element return head
    if (!head || !head -> next) return head;
    
    // make a temp variable that point to the next val of head to save it refrence
    Node *temp = head -> next;
    
    // for the 1st element in dll we need to set its next to null as it is tail
    // and prev to temp (which was next el to head)
    head -> next = nullptr;
    head -> prev = temp;
    
    // run loop till temp reach null
    while (temp){
        
        // update value of head and temp
        head = temp;
        temp = temp -> next;
        
        // reversing the links
        head -> next = head -> prev;
        head -> prev = temp;
    }
    return head;
}
