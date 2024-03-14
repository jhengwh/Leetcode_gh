/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry = 0;
    struct ListNode *lAdd = NULL, *prev = NULL;
    while (true) {
        /** When a zero value in the most significant bit;
         * a zero in units digit is not included. */
        if (!l1 && !l2 && !carry && lAdd)
            break;

        /** When there are non-values, or a zero in units digit. */

        int digit1 = 0, digit2 = 0;
        if (l1) {
            digit1 = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            digit2 = l2->val;
            l2 = l2->next;
        }

        /* List construction */
        struct ListNode* new = calloc(1, sizeof(struct ListNode));
        if (!new)
            ;    // raise error
        if (!lAdd)
            lAdd = new;
        if (prev)
            prev->next = new;
        prev = new;

        /* Value assignment */
        int sum = digit1 + digit2 + carry;
        new->val = (sum % 10);
        new->next = NULL;
        carry = sum / 10;
    }
    return lAdd;
}