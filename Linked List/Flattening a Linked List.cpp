// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// https://takeuforward.org/data-structure/flattening-a-linked-list/

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

// this fn will merge two sorted lists and return head of merged list
// just ike merge sort merge function
Node *merge (Node *l1, Node *l2){
    
    // making a dummy node and temp node to traverse
    Node *head = new Node(0);
    Node *temp = head;
    
    while (l1 && l2){
        
        // add smaller node to temp
        if (l1 -> data < l2 -> data) {
            temp -> bottom = l1;
            temp = temp -> bottom;
            l1 = l1 -> bottom;
        }
        else {
            temp -> bottom = l2;
            temp = temp -> bottom;
            l2 = l2 -> bottom;
        }
    }    
    // check if not null else add to temp
    if (l1) temp -> bottom = l1;
    if (l2) temp -> bottom = l2;
        
    // since the l1 1st nodes next will point to l2, we need to make it null
    head -> bottom -> next = nullptr;
    return head -> bottom;
}

// flatten the ll while backtracking
// we will take the last two nodes merge them
// then this merged node will be taken as l2 and previous node l1
// till recursive calls are complete
Node *flatten(Node *root)
{
    // base case
    if (!root || !root -> next) return root;
   
    // extracting the two nodes to be merged
    // 2nd node from recursive call
    Node *l1 = root;
    Node *l2 = flatten(root -> next);
    
    // merge l1 and l2 and return result
    return merge(l1, l2);
}
