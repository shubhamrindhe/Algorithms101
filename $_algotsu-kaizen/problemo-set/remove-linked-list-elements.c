/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* node, int val) {
    if (node == NULL) return NULL;
    node->next = removeElements(node->next, val);
    return node->val == val ? node->next : node;
}
