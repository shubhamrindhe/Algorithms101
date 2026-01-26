/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode *current, *next;

    if (list1->val < list2->val) {
        current = list1;
        next = list2;
    } else {
        current = list2;
        next = list1;
    }

    current->next = mergeTwoLists(current->next, next);
    return current;
}
