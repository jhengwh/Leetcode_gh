/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (!head)
            return nullptr;

        // Interweave old & new nodes
        Node* curr = head;
        while (curr) {
            Node* new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }

        // Assign *random
        curr = head;
        while (curr) {
            if (curr->random)    // (1)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Seperate old & new nodes to two lists
        Node* new_head = head->next;
        Node* curr_old = head;
        Node* curr_new = new_head;
        while (curr_old) {
            curr_old->next = curr_old->next->next;
            curr_new->next = (curr_new->next) ? curr_new->next->next : nullptr;
            curr_old = curr_old->next;
            curr_new = curr_new->next;
        }

        return new_head;
    }
};