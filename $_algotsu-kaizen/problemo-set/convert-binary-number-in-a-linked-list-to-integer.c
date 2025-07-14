/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getDecimalValue(struct ListNode* _) {
    register int result = 0x0;
    while (_) {
        result = result << 0x1 | _->val;
        _ = _->next;
    }
    return result;
}
