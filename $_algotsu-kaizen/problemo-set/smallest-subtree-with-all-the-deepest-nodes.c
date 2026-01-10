/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* node, int depth, int *max_depth, struct TreeNode** subtree) {
    if (node == NULL) return depth;
    ++depth;

    // int depths[0x2] = {
    //     dfs(node->left, depth, max_depth, deepest_nodes_count, subtree),
    //     dfs(node->right, depth, max_depth, deepest_nodes_count, subtree)
    // };

    int left = dfs(node->left, depth, max_depth, subtree);
    int right = dfs(node->right, depth, max_depth, subtree);

    int max = depth;
    if (max < left) max = left;
    if (max < right) max = right;
    // depths[0x0] > depths[0x1] ? depths[0x0] : depths[0x1];

    if (*max_depth <= depth) {
        if (*max_depth < depth) *max_depth = depth;
        *subtree = NULL;
        // printf("\n %d [%d]", node->val, *max_depth);
    }

    if (
        (*subtree == NULL && max == *max_depth)
        || (left == right && left == *max_depth)
        /*&& (depth == 0x1 || depth != max)*/
    ) {
        *subtree = node;
        // printf("\n [%d]", node->val);
    }

    // printf("\n [%d], %d -> { %d, %d }", depth, node->val, depths[0], depths[1]);
    // printf("\n [%d] %d, %d", depth, max, node->val);
    return max;
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    struct TreeNode* subtree = NULL;
    int max_depth = 0x0;//, deepest_nodes_count = 0x0;
    dfs(root, 0x0, &max_depth, &subtree);

    return subtree ? subtree : root;
}
