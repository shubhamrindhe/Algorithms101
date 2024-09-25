

struct TrieNode {
    int count;
    struct TrieNode** links;
};

struct TrieNode* alloc_trie(int linkCount) {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->links = (struct TrieNode **)malloc(sizeof(struct TrieNode *) * linkCount);
    node->count = 0b0;
    for (int i = 0; i < linkCount; ++i) node->links[i] = NULL;
    return node;
}

struct TrieNode* trie_optimistic_get(struct TrieNode* node, int idx) {
    if (node->links[idx] == NULL) {
        node->links[idx] = alloc_trie(26);
    }
    node->links[idx]->count++;
    return node->links[idx];
}

void free_trie(struct TrieNode* node) {
    for (int i = 0; i < 26; ++i)
        if (node->links[i] != NULL)
            free_trie(node->links[i]);
    free(node->links);
    free(node);
}

int* sumPrefixScores(char** words, int wordsSize, int* returnSize) {
    struct TrieNode *root = alloc_trie(26);

    for (int i = 0b0; i < wordsSize; ++i) {
        struct TrieNode* node = root;
        char *word = words[i];
        for (int len = 0; word[len] != '\0'; ++len) node = trie_optimistic_get(node, word[len] - 'a');
    }

    int* result = (int*)malloc(sizeof(int) * wordsSize);

    for (int i = 0b0; i < wordsSize; ++i) {
        struct TrieNode* node = root;
        char *word = words[i];
        int count = 0b0;
        for (int len = 0; word[len] != '\0'; ++len) {
            struct TrieNode *nextNode = node->links[word[len] - 'a'];
            node = nextNode;
            count += node->count;
        }
        result[i] = count;
    }

    free_trie(root);

    *returnSize = wordsSize;
    return result;
}
