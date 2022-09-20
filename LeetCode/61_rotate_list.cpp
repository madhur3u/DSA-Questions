// https://leetcode.com/problems/rotate-list/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        // when no element or only one element in the linke list
        if (!head || !head -> next) return head;
        
        // first we need to count the no. of el in ll and also the tail node
        int n = 1;
        ListNode *tail = head;
        ListNode *temp = head;
        
        // calculating n and finding tail node
        while (tail -> next){
            n++;
            tail = tail -> next;
        }
        
        // update k for k >= n cases
        k = k % n;
        
        // if k == 0 means after rotation we will get same ll so return head
        if (k == 0) return head;
        
        // now make k, position from starting by subtracting it from n
        k = n - k;
        
        // traverse till we reach the element after which we need to rotate the ll
        // temp will be the last node in rotated ll
        while (k > 1){
            temp = temp -> next;
            k--;
        }
        // now rotate the list first join tail with head to make a circular ll
        // then update head which will be next element to temp
        // break circular ll by making temp-> next as null
        // return updated head
        tail -> next = head;
        head = temp -> next;
        temp -> next = nullptr;
        
        return head;
    }
};
