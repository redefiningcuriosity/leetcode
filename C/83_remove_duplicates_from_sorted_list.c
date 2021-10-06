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


struct ListNode* deleteDuplicates(struct ListNode* head){

    /* Check if no nodes or single node present. */
    if (head == NULL || head->next == NULL)
        return head;
    
    struct ListNode *temp = head;
    
    /* Loop till all nodes, check if nodes match, if they do drop the duplicate node. */
    while(temp->next != NULL)
    {
        if(temp->val == temp->next->val)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    
    return head;
}