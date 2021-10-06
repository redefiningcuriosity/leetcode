/*
 * Time complexity : O(n) where n =  number of nodes in Linked List.
 *
 * Space complexity : O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 /* Use Floyd's Circle Detection Algorithm. */

bool hasCycle(struct ListNode *head) {
    
    if(head==NULL)
        return false;
    
    struct ListNode *slowP = head, *fastP = head->next;
    
    while((slowP != NULL) && (fastP != NULL) && (fastP->next!=NULL))
    {
        slowP = slowP->next;
        fastP = fastP->next->next;
        if (slowP == fastP) {
            return true;
        }
    }
    return false;
    
}