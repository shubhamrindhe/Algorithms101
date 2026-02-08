/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

static inline int heightuh(struct TreeNode *node, bool *is_balanced) {
    if (node == NULL || !(*is_balanced)) return 0x0;
    int left = heightuh(node->left, is_balanced), right = heightuh(node->right, is_balanced);
    *is_balanced &= abs(left - right) <= 0x1;
    return maximus(left, right) + 0x1;
}

bool isBalanced(struct TreeNode* root) {
    bool is_balanced = true;
    heightuh(root, &is_balanced);
    return is_balanced;// root == NULL || abs(heightuh(root->left) - heightuh(root->right)) <= 0x1;
}
