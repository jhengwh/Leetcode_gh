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

/* My original attempt (too complex, see organized one) */
bool isPalindrome(struct ListNode* head)
{
    struct ListNode *crawl = head, *half = head;
    int listLen = 1;
    while (crawl->next) {
        crawl = crawl->next;
        listLen++;
    }
    if (listLen == 1) {
        return true;
    } else if (listLen % 2) {    // The list has odd number nodes
        half = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        crawl = head;
        for (int i = 0; i < (listLen / 2); i++)
            crawl = crawl->next;     // Move to the middle node.
        half->val = crawl->val;      // Make both the first and the second half list
        half->next = crawl->next;    // has even number nodes.
    } else {
        for (int i = 0; i < (listLen / 2); i++)
            half = half->next;    // move to the middle node
    }
    half = reverseList(half);
    while (half) {
        if (head->val != half->val)
            return false;
        head = head->next;
        half = half->next;
    }
    return true;
}