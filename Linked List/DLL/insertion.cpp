// https://practice.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
   // store value next to head in a node curr
   // store value of head in temp so head unchanged
   Node *curr = head -> next;
   Node *temp = head;
   
   // run till we reached pos to be inserted
   while (pos != 0){
       temp = curr;
       curr = curr -> next;
       pos--;
   }
   
   // make new node fill data
   Node *ins = new Node(data);
   
   // we need to insert the node b/w temp and curr
   // if curr is null then insert b/w last value i.e. temp and null
   // making all links accordingly
   temp -> next = ins;
   ins -> prev = temp;
   ins -> next = curr;
   if (curr) curr -> prev = ins;
}
