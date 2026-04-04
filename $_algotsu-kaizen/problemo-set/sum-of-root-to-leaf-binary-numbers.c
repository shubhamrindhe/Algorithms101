/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode *node, int value) {
    if (node == NULL) return value;
    value = (value << 0x1) + node->val;
    if (node->left == NULL && node->right == NULL) return value;
    return (node->left != NULL ? dfs(node->left, value) : 0x0)
    + (node->right != NULL ? dfs(node->right, value) : 0x0);
}

int sumRootToLeaf(struct TreeNode* root) {
    return dfs(root, 0x0);
}
