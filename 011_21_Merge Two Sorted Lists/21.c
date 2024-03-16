/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void connectNode(struct ListNode** _node, struct ListNode** _head,
    struct ListNode** _prev)
{
    if (!(*_head))
        *_head = *_node;
    if (*_prev)
        (*_prev)->next = *_node;
    *_prev = *_node;
    *_node = (*_node)->next;
}

struct ListNode* mergeTwoLists(struct ListNode* list1,
    struct ListNode* list2)
{
    struct ListNode *head = NULL, *prev = NULL;

    while (list1 && list2) {
        if (list2->val < list1->val)
            connectNode(&list2, &head, &prev);
        else
            connectNode(&list1, &head, &prev);
    }

    if (list1)
        connectNode(&list1, &head, &prev);
    if (list2)
        connectNode(&list2, &head, &prev);

    return head;
}