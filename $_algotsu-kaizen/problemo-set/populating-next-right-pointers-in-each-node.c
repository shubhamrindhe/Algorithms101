/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* dfs(struct Node* node, int level, struct Node **lavel_list) {
    if (node == NULL) return node;
    if (lavel_list[level]) lavel_list[level]->next = node;
    lavel_list[level] = node;
    dfs(node->left, level + 0x1, lavel_list);
    dfs(node->right, level + 0x1, lavel_list);
    return node;
}

struct Node* connect(struct Node* root) {
    struct Node *lavel_list[0x1 << 0xC];
    return dfs(root, 0x0, lavel_list);
}
