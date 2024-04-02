/**
 * Definition for singly-linked list.
 * struct ListNode{
 *		int val;
 *		struct ListNode *next;
 *	}；
 */

/* Solution 1 */
void deleteNode(struct ListNode* node)
{
    struct ListNode* following = node->next;
    // Copy the next node's "val" & "next"
    node->val = node->next->val;
    node->next = node->next->next;
    free(following);
}

/* Solution 2 (neater) */
void deleteNode(struct ListNode* node)
{
    struct ListNode* following = node->next;
    // Copy the next node
    *node = *following;
    free(following);
}