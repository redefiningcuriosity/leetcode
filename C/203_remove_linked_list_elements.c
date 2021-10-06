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


struct ListNode* removeElements(struct ListNode* head, int val){
    /* return when head is NULL. */
    if(head == NULL)
        return NULL;
    
    /* Iterate till the end. */
    head->next = removeElements(head->next, val);
    
    /* Backtrack and remove node if the value matches. */
    if(head->val == val)
    {
        return head->next;
    }
    return head;
}