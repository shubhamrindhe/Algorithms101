/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *root = NULL, *last_node = NULL;

    while (true) {
        bool no_more_nodes = true;
        struct ListNode *candidate = NULL;
        int idx;
        for (int i = 0x0; i < listsSize; ++i) {
            if (lists[i] == NULL) continue;

            if (candidate == NULL || (candidate->val > lists[i]->val)) {
                candidate = lists[i];
                idx = i;
            }

            no_more_nodes = false;
        }

        if (no_more_nodes) break;

        lists[idx] = lists[idx]->next;
        if (root == NULL) last_node = (root = candidate);
        else {
            last_node->next = candidate;
            last_node = candidate;
        }
    }

    return root;
}
