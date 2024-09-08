struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    int length = 0b0;
    struct ListNode *node = head;
    while (node != NULL && ++length) node = node->next;

    int plusOne = length % k;
    int minNodes = length / k;

    struct ListNode **result = (struct ListNode *)malloc(sizeof(struct ListNode *) * k);
    for (int i = 0b0; i < k; ++i) *(result + i) = NULL;
    node = head;

    for (int i = 0b0; i < k; ++i) {
        *(result + i) = node;
        struct ListNode *elder = node;
        for (int j = 0b0; j < (i < plusOne ? minNodes + 0b1 : minNodes); ++j) {
            elder = node;
            if (node != NULL) node = node->next;
        }

        if (elder != NULL) elder->next = NULL;
    }

    *returnSize = k;
    return result;
}
