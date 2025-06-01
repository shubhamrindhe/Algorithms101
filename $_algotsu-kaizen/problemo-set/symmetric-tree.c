/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool _(struct TreeNode* one, struct TreeNode* two) {
    if (one == NULL || two == NULL) return one == NULL && two == NULL;
    return one->val == two->val && _(one->left, two->right) && _(one->right, two->left);
}

bool isSymmetric(struct TreeNode* root) {
    return _(root->left, root->right);
}
