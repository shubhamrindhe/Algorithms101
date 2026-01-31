/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

const int section_count = 0x2;

// int put_node_in_section(const int section_size,
//                         struct ListNode* node,
//                         struct ListNode **section_heads,
//                         struct ListNode ***section_tail_hooks) {

// }

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *first_part_head = NULL, *second_part_head = NULL;
    // struct ListNode **first_part_tail_hook = &first_part_head,
    //                 **second_part_tail_hook = &second_part_head;
    // struct ListNode **section_tail_hooks[section_count] = { &first_part_head, &second_part_head };

    struct ListNode *section_heads[section_count];
    struct ListNode **section_tail_hooks[section_count];

    for (int i = 0x0; i < 0x2; ++i) {
        section_heads[i] = NULL;
        section_tail_hooks[i] = &(section_heads[i]);
    }

    struct ListNode *_ = head;

    while (_) {
        // if (_->val < x) {
        //     *first_part_tail_hook = _;
        //     first_part_tail_hook = &(_->next);
        // } else {
        //     *second_part_tail_hook = _;
        //     second_part_tail_hook = &(_->next);
        // }

        int idx = _->val < x ? 0x0 : 0x1;
        *(section_tail_hooks[idx]) = _;
        section_tail_hooks[idx] = &(_->next);

        _ = _->next;
    }

    // *first_part_tail_hook = second_part_head;
    // *second_part_tail_hook = NULL;
    // *section_tail_hooks[0x0] = second_part_head;
    // *(section_tail_hooks[0x1]) = NULL;

    int i = section_count - 0x1;
    _ = NULL;
    do {
        *(section_tail_hooks[i]) = _;
        _ = section_heads[i];
        --i;
    } while(i >= 0x0);

    return section_heads[0x0];
}
