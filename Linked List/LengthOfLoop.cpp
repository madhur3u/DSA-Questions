int cycleLength(struct Node *beg, struct Node *slow){
        
        while (beg != slow){
            beg = beg -> next;
            slow = slow -> next;
        }
        
        slow = slow -> next;
        int count = 1;
        
        while (slow != beg){
            slow = slow -> next;
            count++;
        }
        return count;
}

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
        Node* slow = head;
        Node* fast = head;
        
        while (fast && fast -> next){
            
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if (slow == fast) return cycleLength(head, slow);
        }
        // no loop
        return 0;
}
