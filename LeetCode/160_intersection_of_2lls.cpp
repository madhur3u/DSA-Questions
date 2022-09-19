// https://leetcode.com/problems/intersection-of-two-linked-lists/ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // make dummy nodes at head of both
        ListNode *a = headA;
        ListNode *b = headB;
        
        // run loop till both points to same node
        // both will be pointing to null in case of no intersection
        while (a != b){
            // a = (a == nullptr) ? headB : a -> next;
            // b = (b == nullptr) ? headA : b -> next;
            
            // inc a till we reach null ans if we find null place a at b ll
            // if a was smaller it will reach null first
            // this way when it is at b after null
            // and we inc both nodes till b reach null
            // after b reach null we have b pointer at A node
            // and a pointer in b node after difference (b - a)
            // so if we now inc both nodes one by one we will find intersection
            if (a == nullptr)   a = headB;
            else                a = a -> next;
            
            if (b == nullptr)   b = headA;
            else                b = b -> next;
        }
        return a;
    }
};

/*
Visualization of this solution:
Case 1 (Have Intersection & Same Len):

       a
A:     a1 → a2 → a3
                   ↘
                     c1 → c2 → c3 → null
                   ↗            
B:     b1 → b2 → b3
       b
            a
A:     a1 → a2 → a3
                   ↘
                     c1 → c2 → c3 → null
                   ↗            
B:     b1 → b2 → b3
            b
                 a
A:     a1 → a2 → a3
                   ↘
                     c1 → c2 → c3 → null
                   ↗            
B:     b1 → b2 → b3
                 b
A:     a1 → a2 → a3
                   ↘ a
                     c1 → c2 → c3 → null
                   ↗ b            
B:     b1 → b2 → b3
Since a == b is true, end loop while(a != b), return the intersection node a = c1.

Case 2 (Have Intersection & Different Len):

            a
A:          a1 → a2
                   ↘
                     c1 → c2 → c3 → null
                   ↗            
B:     b1 → b2 → b3
       b
                 a
A:          a1 → a2
                   ↘
                     c1 → c2 → c3 → null
                   ↗            
B:     b1 → b2 → b3
            b
A:          a1 → a2
                   ↘ a
                     c1 → c2 → c3 → null
                   ↗            
B:     b1 → b2 → b3
                 b
A:          a1 → a2
                   ↘      a
                     c1 → c2 → c3 → null
                   ↗ b           
B:     b1 → b2 → b3
A:          a1 → a2
                   ↘           a
                     c1 → c2 → c3 → null
                   ↗      b           
B:     b1 → b2 → b3
A:          a1 → a2
                   ↘                a = null, then a = b1
                     c1 → c2 → c3 → null
                   ↗           b           
B:     b1 → b2 → b3
A:          a1 → a2
                   ↘ 
                     c1 → c2 → c3 → null
                   ↗                b = null, then b = a1 
B:     b1 → b2 → b3
       a
            b         
A:          a1 → a2
                   ↘ 
                     c1 → c2 → c3 → null
                   ↗
B:     b1 → b2 → b3
            a
                 b         
A:          a1 → a2
                   ↘ 
                     c1 → c2 → c3 → null
                   ↗ 
B:     b1 → b2 → b3
                 a
A:          a1 → a2
                   ↘ b
                     c1 → c2 → c3 → null
                   ↗ a
B:     b1 → b2 → b3
Since a == b is true, end loop while(a != b), return the intersection node a = c1.

Case 3 (Have No Intersection & Same Len):

       a
A:     a1 → a2 → a3 → null
B:     b1 → b2 → b3 → null
       b
            a
A:     a1 → a2 → a3 → null
B:     b1 → b2 → b3 → null
            b
                 a
A:     a1 → a2 → a3 → null
B:     b1 → b2 → b3 → null
                 b
                      a = null
A:     a1 → a2 → a3 → null
B:     b1 → b2 → b3 → null
                      b = null
Since a == b is true (both refer to null), end loop while(a != b), return a = null.

Case 4 (Have No Intersection & Different Len):

       a
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
       b
            a
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
            b
                 a
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
                 b
                      a
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
                      b = null, then b = a1
       b                   a = null, then a = b1
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
            b                   
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
       a
                 b
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
            a
                      b
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
                 a
                           b = null
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
                      a = null
Since a == b is true (both refer to null), end loop while(a != b), return a = null.

*/
