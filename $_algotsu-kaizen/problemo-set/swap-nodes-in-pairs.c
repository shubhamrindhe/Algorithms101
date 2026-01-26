/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode *node) {
    if (node == NULL || node->next == NULL) return node;
    struct ListNode *root = node->next;
    node->next = swapPairs(node->next->next);
    root->next = node;
    return root;
}
