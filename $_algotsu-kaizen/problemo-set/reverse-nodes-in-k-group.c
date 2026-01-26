/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// void print_ll(struct ListNode* _) {
//     printf("\n");
//     while (_) printf(" %d ", _->val), _ = _->next;
// }

struct ListNode* squash_stack(int k, struct ListNode* stack[k], int top) {
    if (top < 0x0) return NULL;
    if (top != (k - 0x1)) return stack[0x0];

    struct ListNode *head = top >= 0x0 ? stack[top] : NULL;
    for (int i = top; i > 0x0; --i) stack[i]->next = stack[i - 0x1];
    stack[0x0]->next = NULL;
    return head;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k == 0x1) return head;

    struct ListNode *new_head = NULL, *tail = NULL, *_ = head;
    struct ListNode **tail_anchor = &new_head;

    struct ListNode* stack[k];
    int top = -0x1;

    while (_) {
        if (top == (k - 0x1)) {
            // struct ListNode* rev_segment_head = squash_stack(k, stack, top);
            // if (new_head == NULL) new_head = rev_segment_head;
            // if (tail != NULL) tail->next = rev_segment_head;
            *tail_anchor = squash_stack(k, stack, top);

            tail = stack[0x0];
            tail_anchor = &(tail->next);
            top = -0x1;
            continue;
        }

        stack[++top] = _;
        _ = _->next;
    }

    if (top >= 0x0) *tail_anchor = squash_stack(k, stack, top);

    // print_ll(new_head);
    return new_head;
}
