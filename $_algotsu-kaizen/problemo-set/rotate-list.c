/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// int len_ll(struct ListNode* node) {
//     return node == NULL ? 0x0 : len_ll(node->next) + 0x1;
// }

// int nth_last(struct ListNode* node, int n, struct ListNode **nth_last_ptr, struct ListNode **last_ptr) {
//     if (node == NULL) return 0x0;
//     int xdi = nth_last(node->next, n, nth_last_ptr, last_ptr);
//     if (xdi == 0x0) *last_ptr = node;
//     if (n == xdi) *nth_last_ptr = node;
//     return xdi + 0x1;
// }

struct ListNode* nth_node(struct ListNode* node, int n, int tag) {
    if (node == NULL) return NULL;
    if (n == tag) return node;
    return nth_node(node->next, n, tag + 0x1);
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL) return head;
    int length = 0x0; // len_ll(head);

    struct ListNode *_= head, *last_node = NULL, **head_ptr = &head;
    while (_ && ++length) {
        if (_->next == NULL) last_node = _;
        _ = _->next;
    }

    int effective_shifts = k % length;

    if (effective_shifts > 0x0) {
        // printf("len: %d %d", effective_shifts, k - effective_shifts);
        struct ListNode *severed_node = nth_node(head, length - effective_shifts, 0x1);
        // printf("\nDEV: %d", severed_node != NULL ? severed_node->val : -0x1);
        last_node->next = head;
        *head_ptr = severed_node->next;
        severed_node->next = NULL;
        // struct ListNode *severed_node = NULL, *last_node = NULL;
        // nth_last(head, effective_shifts, &severed_node, &last_node);
    }

    return *head_ptr; // last_node;
}
