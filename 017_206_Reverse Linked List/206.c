/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *prev = NULL, *following = NULL;
    // "head" acts as "current"
    while (head) {
        following = head->next;
        head->next = prev;
        prev = head;
        head = following;
    }
    return prev;
}