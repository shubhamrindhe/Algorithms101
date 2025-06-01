#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* node) {
    if (node == NULL) return 0b0;
    int ldepth = node->left ? maxDepth(node->left) : 0b0;
    int rdepth = node->right ? maxDepth(node->right) : 0b0;
    return MAX(ldepth, rdepth) + 0b1;
}
