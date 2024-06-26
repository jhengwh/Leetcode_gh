/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode *a = headA, *b = headB;
    while (a != b) {
        a = (!a) ? headB : a->next;
        b = (!b) ? headA : b->next;
    }
    return a;
}