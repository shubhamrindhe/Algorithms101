/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *new_head = NULL;
    struct ListNode **tail_hook = &new_head;

    struct ListNode *_ = head;
    for (int i = 0x1; i < left; ++i) {
        *tail_hook = _;
        tail_hook = &(_->next);
        _ = _->next;
    }

    int segment_length = right - left + 0x1;
    struct ListNode *stack[segment_length];
    int top = -0x1;

    for (int i = 0x0; i < segment_length; ++i) {
        stack[++top] = _;
        _ = _->next;
    }

    if (top >= 0x0) stack[0x0]->next = stack[top]->next;
    *tail_hook = stack[top];

    while (top > 0x0) {
        stack[top]->next = stack[top - 0x1];
        *tail_hook = stack[top];
        tail_hook = &(stack[top]->next);
        --top;
    }

    return new_head;
}
