/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void fill_inorder(struct TreeNode *node, struct TreeNode **list, int *list_len) {
    if (node == NULL) return;
    fill_inorder(node->left, list, list_len);
    list[(*list_len)++] = node;
    // printf(" %d ", node->val);
    fill_inorder(node->right, list, list_len);
}

struct TreeNode* balance(struct TreeNode **list, int l, int r) {
    if (l > r) return NULL;
    int m = l + (r - l) / 0x2;
    struct TreeNode *node = list[m];
    node->left = balance(list, l, m - 0x1);
    node->right = balance(list, m + 0x1, r);
    return node;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    struct TreeNode *list[10000];
    int list_len = 0x0;
    fill_inorder(root, list, &list_len);
    return balance(list, 0x0, list_len - 0x1);
}
