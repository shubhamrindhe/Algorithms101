/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* node = head ? head->next : NULL;
    struct ListNode* _ = head;

    while (node) {
        if (_ && node && (_->val == node->val)) {
            while (_ && node && (_->val == node->val)) node = node->next;
            _->next = node;
        }
        _ = node;
        node = node ? node->next : NULL;
    }

    return head;
}
