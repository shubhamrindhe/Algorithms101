/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 struct TreeNode* new_node(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    if (node) {
        node->val = value;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

struct TreeNode* construct(char* string, int *idx, int depth) {
    if (string[*idx] == '\0') return NULL;

    int dashes = 0;
    while (string[*idx + dashes] == '-' && ++dashes);

    if (dashes != depth) return NULL;

    *idx += dashes;

    int value = 0, digits = 0;
    char _;
    while ((_ = string[*idx + digits]) && _ != '-' && ++digits) value = value * 0b1010 + (_ - '0');

    *idx += digits;

    struct TreeNode *node = new_node(value);
    node->left = construct(string, idx, depth + 0b1);
    node->right = construct(string, idx, depth + 0b1);

    return node;
}

struct TreeNode* recoverFromPreorder(char* traversal) {
    int idx = 0b0;
    return construct(traversal, &idx, 0b0);
}
