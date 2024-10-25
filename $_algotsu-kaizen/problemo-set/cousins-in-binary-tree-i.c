/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int get_depth(int level, struct TreeNode* node) {
    int leftDepth = node->left == NULL ? level : get_depth(level + 1, node->left);
    int rightDepth = node->right == NULL ? level : get_depth(level + 1, node->right);
    return  leftDepth > rightDepth ? leftDepth : rightDepth;
}

void sigma_depth(int* sigma, int size, int level, struct TreeNode* node) {
    sigma[level] += node->val;
    if (node->left != NULL) sigma_depth(sigma, size, level + 1, node->left);
    if (node->right != NULL) sigma_depth(sigma, size, level + 1, node->right);
}

void adjust(int* sigma, int size, int level, struct TreeNode* node, struct TreeNode* sibling) {
    node->val = sigma[level] - node->val - (sibling == NULL ? 0 : sibling->val);

    if (node->left != NULL) adjust(sigma, size, level + 1, node->left, node->right);
    if (node->right != NULL) adjust(sigma, size, level + 1, node->right, node->left);
}

void adjust_val(int* sigma, int level, struct TreeNode* node, int siblingValue) {
    if (node == NULL) return;
    int originalValue = node->val;
    int rightVal = node->right != NULL ? node->right->val : 0;
    int leftVal = node->left != NULL ? node->left->val : 0;
    if (node->left != NULL) adjust_val(sigma, level + 1, node->left, rightVal);
    if (node->right != NULL) adjust_val(sigma, level + 1, node->right, leftVal);
    node->val = sigma[level] - originalValue - siblingValue;
}

struct TreeNode* replaceValueInTree(struct TreeNode* root) {
    int _depth_ = get_depth(1, root);
    int* sigma = (int *)malloc(sizeof(int) * _depth_);
    for (int i=0; i < _depth_;++i) sigma[i] = 0;
    sigma_depth(sigma, _depth_, 0, root);
    adjust_val(sigma, 0, root, 0);
    return root;
}
