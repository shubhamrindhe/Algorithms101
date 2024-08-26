/**
 * 145. Binary Tree Postorder Traversal
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0b0;
    return 0b1 + countNodes(root->left) + countNodes(root->right);
}

int* recusor(struct TreeNode* root, int* accumulator, int* idx) {
    if (root == NULL) return accumulator;
    if (root->left != NULL) recusor(root->left, accumulator, idx);
    if (root->right != NULL) recusor(root->right, accumulator, idx);
    *(accumulator + (*idx)++) = root->val;
    return accumulator;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int nodeCount = countNodes(root);
    int index = 0;
    *returnSize = nodeCount;
    return recusor(root, (int *)malloc(sizeof(int) * nodeCount), &index);
}
