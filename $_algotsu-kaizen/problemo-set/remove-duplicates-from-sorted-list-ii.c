/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return head;

    struct ListNode *new_head = NULL;//, *tail = NULL;
    struct ListNode **tail_hook = &new_head;

    struct ListNode *candidate = head;
    int prev_val = INT_MIN;

    while (candidate) {
        if (
            (
                candidate->val > prev_val
            ) && (
                candidate->next == NULL || (candidate->next->val > candidate->val)
            )
        ) {
            // if (new_head == NULL) {
            //     new_head = candidate;
            //     tail = new_head;
            // } else {
            //     tail->next = candidate;
            //     tail = candidate;
            // }

            *tail_hook = candidate;
            tail_hook = &(candidate->next);
        }

        prev_val = candidate->val;
        candidate = candidate->next;
    }

    *tail_hook = NULL;
    // if (tail) tail->next = NULL;

    return new_head;
}
