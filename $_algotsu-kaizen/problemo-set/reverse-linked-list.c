/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* node, struct ListNode* parent) {
    if (node == NULL) return NULL;
    bool is_last = node->next == NULL;
    struct ListNode* new_head = is_last ? node : reverse(node->next, node);
    node->next = parent;
    return new_head;
}

struct ListNode* reverseList(struct ListNode* head) {
    // struct ListNode *rev_head = NULL;
    // struct ListNode *_ = head, *prev = NULL;
    // while (_ != NULL) {
    //     _ = _->next;
    // }
    return reverse(head, NULL);
}
