class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
        //Code here
        int count = 1;
        Node* temp = head;
        while (temp -> next != NULL){
            count++;
            temp = temp -> next;
        }
        return count;
    }
};
