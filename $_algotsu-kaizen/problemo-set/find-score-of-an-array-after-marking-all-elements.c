
typedef struct Node {
    int data;
    int idx;
    struct Node *next;
} Node;

Node* new_node(int idx, int data, Node* next) {
    Node* node = (Node *)malloc(sizeof(Node));
    node->idx = idx;
    node->data = data;
    node->next = next;
    return node;
}

Node* insert_node(Node* root, Node* node) {
    if (root->data > node->data) {
        node->next = root;
        return node;
    }

    Node* _ = root;
    while (_ && (_->next) && (_->next->data <= node->data)) _ = _->next;
    node->next = _->next;
    _->next = node;
    return root;
}

void print(Node * node) {
    Node* _ = node;
    printf("\n");
    while (_) {
        printf(" ( %d, %d ) ", _->idx, _->data);
        _ = _->next;
    }
    printf("\n");
}

// TLE
long long findScore(int* nums, int numsSize) {
    Node* root = new_node(0, nums[0], NULL);
    for (int i = 1; i < numsSize; ++i) root = insert_node(root, new_node(i, nums[i], NULL));

    bool* marked = (bool *)calloc(numsSize, sizeof(bool));
    long long result = 0;

    while (root) {
        while (root && marked[root->idx]) {
            Node * _ = root;
            root = root->next;
            free(_);
        }

        if (!root) break;

        marked[root->idx] = true;
        result += root->data;
        if (root->idx > 0) marked[(root->idx) - 1] = true;
        if (root->idx < (numsSize - 1)) marked[(root->idx) + 1] = true;

        Node * _ = root;
        root = root->next;
        free(_);
    }

    return result;
}




long long findScore(int* nums, int numsSize) {
    bool* marked = (bool *)calloc(numsSize, sizeof(bool));
    Node* heap_esque = (Node *)malloc(numsSize * sizeof(Node));

    for (int i = 0; i < numsSize; i++) {
        heap_esque[i].data = nums[i];
        heap_esque[i].idx = i;
    }

    qsort(heap_esque, numsSize, sizeof(Node), compare);
    long long result = 0;
    for (int i = 0; i < numsSize; ++i) {
        int idx = heap_esque[i].idx;
        if (!marked[idx]) {
            result += heap_esque[i].data;
            marked[idx] = true;
            if (idx > 0) marked[idx - 1] = true;
            if (idx < numsSize - 1) marked[idx + 1] = true;
        }
    }

    free(heap_esque);
    free(marked);
    return result;
}