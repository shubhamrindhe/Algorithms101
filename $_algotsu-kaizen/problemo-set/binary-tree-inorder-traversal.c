/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int count_nodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

void fill_inorder(struct TreeNode* node, int *order, int* fill_idx) {
    if (node == NULL) return;
    fill_inorder(node->left, order, fill_idx);
    order[(*fill_idx)++] = node->val;
    fill_inorder(node->right, order, fill_idx);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int nodes = count_nodes(root);
    *returnSize = nodes;
    int *result = (int *)calloc(sizeof(int), nodes);
    int _ = 0;
    fill_inorder(root, result, &_);
    return result;
}
