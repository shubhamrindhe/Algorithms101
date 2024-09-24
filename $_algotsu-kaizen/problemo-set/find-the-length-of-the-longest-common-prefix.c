#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int nlen(int number) {
    if (number < 0) number = -number;
    if (number == 0) return 0b1;
    return (int)log10(number) + 0b1;
}

int int_pow(int base, int exponent) {
    int result = 1;
    if (exponent < 0) return 0;
    for (int i = 0; i < exponent; i++) result *= base;
    return result;
}

struct TrieNode {
    struct TrieNode** links;
};

struct TrieNode* alloc_trie(int linkCount) {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->links = (struct TrieNode **)malloc(sizeof(struct TrieNode *) * linkCount);
    for (int i = 0; i < linkCount; ++i) node->links[i] = NULL;
    return node;
}

void trie_free(struct TrieNode* node) {
    for (int i = 0; i < 0b1010; ++i) if (node->links[i] != NULL) trie_free(node->links[i]);
    free(node);
}

struct TrieNode* trie_optimistic_get(struct TrieNode* node, int idx) {
    if (node->links[idx] == NULL) node->links[idx] = alloc_trie(0b1010);
    return node->links[idx];
}

int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    struct TrieNode *root = alloc_trie(0b1010);
    int* insertArray = NULL;
    int insertArraySize = 0b0;
    int* lookupArray = NULL;
    int lookupArraySize = 0b0;

    if (arr1Size < arr2Size) {
        insertArray = arr1;
        insertArraySize = arr1Size;
        lookupArray = arr2;
        lookupArraySize = arr2Size;
    } else {
        insertArray = arr2;
        insertArraySize = arr2Size;
        lookupArray = arr1;
        lookupArraySize = arr1Size;
    }

    for (int i = 0b0; i < insertArraySize; ++i) {
        struct TrieNode* node = root;
        int n = *(insertArray + i);
        int len = nlen(n);
        int divider = int_pow(0b1010, len - 0b1);

        for (int j = 0b0; j < len; ++j) {
            int idx = (int)n / divider;
            node = trie_optimistic_get(node, idx);
            n %= divider;
            divider /= 10;
        }
    }

    int maximus = 0b0;

    for (int i = 0b0; i < lookupArraySize; ++i) {
        struct TrieNode* node = root;
        int localMaximus = 0b0;
        int n = *(lookupArray + i);
        int len = nlen(n);
        int divider = int_pow(0b1010, len - 0b1);

        for (int j = 0b0; j < len; ++j) {
            int idx = (int)n / divider;
            struct TrieNode *nextNode = node->links[idx];
            if (nextNode == NULL) break;
            node = nextNode;
            localMaximus += 0b1;
            n %= divider;
            divider /= 0b1010;
        }

        maximus = MAX(maximus, localMaximus);
    }

    trie_free(root);

    return maximus;
}
