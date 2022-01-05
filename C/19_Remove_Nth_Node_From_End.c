/*
 * Time complexity : O(n)
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

/* BackTraverse function handles deletion. */
struct ListNode* backTraverse(struct ListNode* ptr, int *backCount, int n)
{
    struct ListNode* temp=NULL;
	
	/* Check for Last node */
    if(ptr == NULL)
    {
        (*backCount) = 1;
        return NULL;
    }
    /* recurse till the end */
    ptr->next = backTraverse(ptr->next, backCount, n);
    
	/* Check if count from end matches n. If yes delete node and return next list item.
	Make backcount as n+1 so that it never matches again. */
    if(n==(*backCount))
    {
        (*backCount) = n+1;
        temp = ptr->next;
        free(ptr);
        return temp;
    }
	/* in other case just increment backCounter and proceed. */
    (*backCount)++;
    return ptr;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int backCount = 0;
    head = backTraverse(head, &backCount, n);
    return head;
}