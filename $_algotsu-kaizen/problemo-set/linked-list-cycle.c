/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;

    struct ListNode *fast = head, *slow = head;

    while (fast->next && fast->next->next)
        if ((slow = slow->next) == (fast = fast->next->next)) return true;

    return false;
}
