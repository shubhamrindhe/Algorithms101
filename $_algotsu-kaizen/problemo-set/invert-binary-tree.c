/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return root;
    struct TreeNode* l = root->left;
    struct TreeNode* r = root->right;
    root->left = invertTree(r);
    root->right = invertTree(l);
    return root;
}
