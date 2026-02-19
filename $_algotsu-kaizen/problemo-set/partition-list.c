/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

const int section_count = 0x2;

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *first_part_head = NULL, *second_part_head = NULL;

    struct ListNode *section_heads[section_count];
    struct ListNode **section_tail_hooks[section_count];

    for (int i = 0x0; i < 0x2; ++i) {
        section_heads[i] = NULL;
        section_tail_hooks[i] = &(section_heads[i]);
    }

    struct ListNode *_ = head;

    while (_) {
        int idx = _->val < x ? 0x0 : 0x1;
        *(section_tail_hooks[idx]) = _;
        section_tail_hooks[idx] = &(_->next);

        _ = _->next;
    }

    int i = section_count - 0x1;
    _ = NULL;
    do {
        *(section_tail_hooks[i]) = _;
        _ = section_heads[i];
        --i;
    } while(i >= 0x0);

    return section_heads[0x0];
}
