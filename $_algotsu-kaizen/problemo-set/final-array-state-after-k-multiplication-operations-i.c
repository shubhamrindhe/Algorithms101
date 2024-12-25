
typedef struct Node {
    int data;
    int idx;
    struct Node *next;
} Node;

Node* new_node(int data, int idx, Node* next) {
    Node* node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->idx = idx; 
    node->next = next;
    return node;
}

Node* insert_node(Node* root, Node* node) {
    if (root == NULL) return node; 
    if (root->data > node->data || (root->data == node->data && root->idx > node->idx)) {
        node->next = root;
        return node;
    } 
    Node* _ = root;
    while (
        _ 
        && (_->next) 
        && (
            (_->next->data < node->data)
            || 
            ((_->next->data == node->data) && (_->next->idx < node->idx))
        )
    ) _ = _->next;
    node->next = _->next;
    _->next = node;
    return root;
}

// void print(Node * node) {
//     Node* _ = node;
//     printf("\n PQ \n");
//     while (_) {
//         printf(" (%d, %d) ", _->idx, _->data);
//         _ = _->next;
//     }
//     printf("\n");
// }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    int* result = (int *)calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    Node* root = NULL;
    for (int i = 0; i < numsSize; ++i) {
        result[i] = nums[i];
        root = insert_node(root, new_node(nums[i], i, NULL));
    }

    // print(root);

    for (int i = 0; i < k; ++i) {
        Node* minNode = root;
        root = root->next;
        minNode->next = NULL;

        result[minNode->idx] = result[minNode->idx] * multiplier;
        minNode->data = result[minNode->idx];
        root = insert_node(root, minNode);

        // print(root);
        // printf("\n");
        // for (int j = 0; j < numsSize; ++j) printf(" %d ", result[j]);
    } 

    return result;
}