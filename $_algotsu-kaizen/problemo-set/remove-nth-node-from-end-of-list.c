/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int remove_nth_last(struct ListNode** head_ptr, struct ListNode* node, int n) {
    if (node == NULL) return 0x0;
    int next_tag = remove_nth_last(head_ptr, node->next, n);
    int tag = next_tag + 0x1;

    // printf(" %d<%d> ", node->val, next_tag);
    // printf(" +[%p %p] ", (void*)*head_ptr, (void*)node);
    if (next_tag == n)
        node->next = node->next == NULL ? NULL : node->next->next;
    else if ((*(head_ptr) == node) && (tag == n))
        *head_ptr = node->next;

    return tag;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* ll_head = head;
    remove_nth_last(&ll_head, head, n);
    return ll_head;
}
