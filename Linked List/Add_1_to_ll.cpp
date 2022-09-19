// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
// https://www.geeksforgeeks.org/add-1-number-represented-linked-list/

/*
Number is represented in linked list such that each digit corresponds to a node in linked list. 
Add 1 to it. For example 1999 is represented as (1-> 9-> 9 -> 9) and adding 1 to it should change it to (2->0->0->0) 

Below are the steps : 

    Reverse given linked list. For example, 1-> 9-> 9 -> 9 is converted to 9-> 9 -> 9 ->1.
    Start traversing linked list from leftmost node and add 1 to it. If there is a carry, move to the next node. 
    Keep moving to the next node while there is a carry.
    Reverse modified linked list and return head.
*/

class Solution
{   
    // function to reverse a LL and return new head
    Node* reverseList(Node* head) {
        
        // base case when head null means no el in list or when next el is null means this is last el
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        // new head will go to all the way to last, and will store last node which will now be new nead
        Node* newHead = reverseList(head -> next);
        
        // currently head will be 2nd last el when backtracing starts
        // so we make its next el and change pointer direction
        Node* next = head -> next;
        next -> next = head;
        head -> next = nullptr;
        
        return newHead;;
    }
    
    public:
    Node* addOne(Node *head) 
    {
        // reverse the ll and update the reversed head
        head = reverseList(head);
        
        // res will have the head of resultant ll
        // temp will be used to store the previous node than head, so when head reach null temp node at last element
        Node *res = head;
        Node *temp = head;
        
        // we need to add 1 in starting, and after that check for carry
        int carry = 1;
        
        // loop runs till node over or carry over
        while (carry && head){
            
            // ex 999
            // first find sum by adding carry and find new carry and sum
            // sum = 9 + 1 = 10 , carry = 1, sum = 0;
            int sum = (head -> data) + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            // update node data
            head -> data = sum;
            
            // temp store current node
            // head go to next node
            temp = head;
            head = head -> next;
        }
        // when we are out of loop and carry still remain -->> 999 case when we add 1 --> 1000
        // so we need to add one nore node in end i.e. carry or 1
        // thats why we have stored prev value in temp, temp next will now point to new node
        if (carry){
            temp -> next = new Node(carry);
        }
        
        // currently our list will be 0001 we need to reverse again and return
        return reverseList(res);
    }
};
