/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int values[100001];
bool result;

int traverse(struct ListNode *node, int idx, bool *palindrome) {
    if (node == NULL) return 0x0;
    values[idx] = node->val;
    int xdi = traverse(node->next, idx + 0x1, palindrome);
    *palindrome &= (values[idx] == values[xdi]);
    return xdi + 0x1;
}

bool isPalindrome(struct ListNode* head) {
    bool result = true;
    traverse(head, 0x0, &result);
    return result;
}
