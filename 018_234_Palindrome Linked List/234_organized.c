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

bool isPalindrome(struct ListNode* head)
{
    struct ListNode *fast = head, *slow = head;
    while (fast && fast->next) {    // 1.
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast == slow)    // The list has only 1 node
        return true;
    slow = reverseList(slow);

    // Using "slow" here because list_len(slow) < list_len(head) = n
    while (slow) {
        if (head->val != slow->val)
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}