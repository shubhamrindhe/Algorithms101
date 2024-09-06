
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *recursor(bool *set, struct ListNode *node, struct ListNode *elder)
{
    if (node == NULL)
        return NULL;
    struct ListNode *next = recursor(set, node->next, node);
    if (*(set + node->val))
    {
        if (elder != NULL)
            elder->next = next;
        return next;
    }
    return node;
}

struct ListNode *modifiedList(int *nums, int numsSize, struct ListNode *head)
{
    if (head == NULL)
        return NULL;
    bool *set = (bool *)malloc(sizeof(bool) * 100001);
    for (int i = 0; i < 100001; ++i)
        *(set + i) = false;
    for (int i = 0; i < numsSize; ++i)
        *(set + *(nums + i)) = true;
    return recursor(set, head, NULL);
}
