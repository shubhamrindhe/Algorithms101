#define BYTE_SL 0b1000L
#define BYTE_S 0b1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    char* flags;
} FindElements;

void set_flag(char *flags, int value) {
    int byte_idx = value / 8;
    int bit_idx = value % 8;
    flags[byte_idx] |= 0b1 << bit_idx;
}

void _(char* flags, struct TreeNode* node, int value) {
    if (node == NULL) return;
    set_flag(flags, value);
    int twice = value * 0b10;
    if (node->left) _(flags, node->left, twice + 0b1);
    if (node->right) _(flags, node->right, twice + 0b10);
}

FindElements* findElementsCreate(struct TreeNode* root) {
    unsigned long maximus = 0;
    for (int i = 0; i < 20; ++i ) maximus += maximus * 2 + 2;
    // printf("[%ul]", max);
    // INT_MAX -> 2147483647
    // maximus -> 3486784400
    FindElements *findElements = (FindElements *)malloc(sizeof(FindElements));
    findElements->flags = (char *)calloc(sizeof(char), (maximus / BYTE_SL) + 1L);
    _(findElements->flags, root, 0b0);
    return findElements;
}

bool findElementsFind(FindElements* obj, int target) {
    int byte_idx = target / BYTE_S;
    int bit_idx = target % BYTE_S;
    return obj->flags[byte_idx] & (0b1 << bit_idx);
}

void findElementsFree(FindElements* obj) {
    free(obj->flags);
    free(obj);
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);
 * findElementsFree(obj);
*/