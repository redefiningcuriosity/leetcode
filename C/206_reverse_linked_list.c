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

struct ListNode* reverseList(struct ListNode* head){

    /* Check if no nodes or single node exist. */
    if(head == NULL || head->next==NULL)
    {
        return head;
    }
    
    /* Iterate Till the end */
    struct ListNode *temp = reverseList(head->next);
    
    /* Reverse the list and return current Pointer. */
    head->next->next = head;
    head->next = NULL;
    
    return temp;
}