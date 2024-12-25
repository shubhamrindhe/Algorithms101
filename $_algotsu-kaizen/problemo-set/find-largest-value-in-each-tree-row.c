/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preprocess(struct TreeNode* node, int* depth_pointer, int* node_count_pointer, int level) {
    if (node == NULL) return;
    ++(*node_count_pointer);
    if (node->left == NULL && node->right == NULL && level > *depth_pointer) *depth_pointer = level;
    if (node->left) preprocess(node->left, depth_pointer, node_count_pointer, level + 0b01);
    if (node->right) preprocess(node->right, depth_pointer, node_count_pointer, level + 0b01);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
    int node_count = 0, depth = 0;
    preprocess(root, &depth, &node_count, 0b01);
    // printf(" %d %d ", node_count, depth);

    int *result = (int *)calloc(depth, sizeof(int));
    *returnSize = depth;

    if (depth == 0) return result;

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * node_count);
    int qlen = 0, idx = 0, level_idx = 0;
    queue[qlen++] = root;

    while (idx < qlen) {
        int level_size = qlen - idx;
        int maximus = INT_MIN;

        for (int i = 0; i < level_size; ++i) {
            struct TreeNode* node = queue[idx + i]; 
            if (node->val > maximus) maximus = node->val;
            if (node->left != NULL) queue[qlen++] = node->left;
            if (node->right != NULL) queue[qlen++] = node->right;
        }

        result[level_idx++] = maximus;
        idx += level_size;
    }

    free(queue);
    return result;
}
