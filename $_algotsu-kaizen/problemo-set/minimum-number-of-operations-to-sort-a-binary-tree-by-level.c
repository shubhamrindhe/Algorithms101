/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0b0;
    return 0b1 + countNodes(root->left) + countNodes(root->right);
}

int minimumOperations(struct TreeNode* root) {
    int n = countNodes(root), result = 0;
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * n);
    int qlen = 0;
    queue[qlen++] = root;
    int idx = 0;
    int idx_map[100001];

    while (idx < qlen) {
        int level_size = qlen - idx;
        int level[level_size];
        int sorted_level[level_size];

        for (int i = 0; i < level_size; ++i) {
            struct TreeNode* node = queue[idx + i]; 
            level[i] = node->val;
            sorted_level[i] = node->val;
            idx_map[node->val] = i;
            if (node->left != NULL) queue[qlen++] = node->left;
            if (node->right != NULL) queue[qlen++] = node->right;

            // level[i] = queue[i]->val;
            // if (queue[i]->left != NULL) queue[qlen++] = queue[i]->left;
            // if (queue[i]->right != NULL) queue[qlen++] = queue[i]->right;
        }

        // printf("\n[%d] \n", level_size);
        // for (int i = 0; i < level_size; ++i) printf(" %d ", sorted_level[i]);

        qsort(sorted_level, level_size, sizeof(int), compare);

        // printf("\n");
        // for (int i = 0; i < level_size; ++i) printf(" %d ", sorted_level[i]);

        for (int i = 0; i < level_size; ++i) {
            if (sorted_level[i] == level[i]) continue;
            int j = idx_map[sorted_level[i]];
            int _i = level[i], _j = level[j];
            level[i] = _j;
            level[j] = _i;
            ++result;
            idx_map[level[i]] = i;
            idx_map[level[j]] = j;
        }

        idx += level_size;
    }

    free(queue);
    return result;
}
