
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* new_node(int data, Node* next) {
    Node* node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

Node* insert_node(Node* root, Node* node) {
    if (root->data < node->data) {
        node->next = root;
        return node;
    }
    Node* _ = root;
    while (_ && (_->next) && (_->next->data > node->data)) _ = _->next;
    node->next = _->next;
    _->next = node;
    return root;
}

// void print(Node * node) {
//     Node* _ = node;
//     printf("\n");
//     while (_) {
//         printf(" %d ", _->data);
//         _ = _->next;
//     }
//     printf("\n");
// }

long long pickGifts(int* gifts, int giftsSize, int k) {
    long long result = gifts[0];
    Node* root = new_node(gifts[0], NULL);
    for (int i = 1; i < giftsSize; ++i) {
        result += gifts[i];
        root = insert_node(root, new_node(gifts[i], NULL));
    }
    // print(root);

    for (int i = 0; i < k; ++i) {
        Node* maxNode = root;
        root = root->next;

        int max = maxNode->data;
        int rem = (int)sqrt(max); 
        maxNode->data = rem;
        maxNode->next = NULL;
        if (root) {
            insert_node(root, maxNode);
        } else {
            root = maxNode; 
        }
        
        // print(root);
        // printf(" %d ", max - rem);
        result -= (long long)(max - rem);
    }
    // print(root);

    return result;
}
