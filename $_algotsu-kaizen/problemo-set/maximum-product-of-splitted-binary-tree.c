const int MOD = 1000000007;

long long dfs(struct TreeNode* node, long long *subtrees_list, int *list_length) {
    if (node == NULL) return 0x0LL;
    long sum_left = dfs(node->left, subtrees_list, list_length);
    long right_sum = dfs(node->right, subtrees_list, list_length);
    long long sigma = node->val + sum_left + right_sum;
    return (subtrees_list[(*list_length)++] = sigma);
}

int maxProduct(struct TreeNode* root) {
    long long subtrees[50001];
    int subtrees_len = 0x0;
    long long sigma = dfs(root, subtrees, &subtrees_len);
    long long result = 0x0LL;

    for (int i = 0x0; i < subtrees_len; ++i) {
        long long a = subtrees[i];
        long long b = sigma - a;
        long long product = (a * b);
        if (result < product) result = product;
    }

    return (int)(result % MOD);
}
