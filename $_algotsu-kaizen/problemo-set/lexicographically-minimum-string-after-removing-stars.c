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

void free_linked(Node* node) {
    if (node == NULL) return;
    if (node->next != NULL) free_linked(node->next);
    free(node);
}

void shift(Node** root, Node* node) {
    node->next = *root;
    *root = node;
}

Node* unshift(Node** root) {
    Node* node = *root;
    *root = node->next;
    return node;
}

Node* commission_node(Node** pool, int data, Node *next) {
    if (*pool == NULL) return new_node(data, next);
    Node* node = unshift(pool);
    node->data = data;
    node->next = next;
    return node;
}

void decommission_node(Node** pool, Node* node) {
    shift(pool, node);
}

char* clearStars(char* s) {
    Node** idx_queue = (Node**)calloc(sizeof(Node*), 0b11010);
    Node** node_stash = (Node**)calloc(sizeof(Node*), 0b1);

    int idx = 0b0;
    char _;
    while (_ = s[idx]) {
        if (_ == '*') {
            for (int i = 0b0; i < 0b11010; ++i) {
                if (idx_queue[i]) {
                    Node *node = unshift(idx_queue + i);
                    s[node->data] = '#';
                    decommission_node(node_stash, node);
                    break;
                }
            }
            s[idx] = '$';
        } else {
            int index = _ - 'a';
            Node* node = commission_node(node_stash, idx, NULL);
            shift(idx_queue + index, node);
        }
        ++idx;
    }

    // for (int i = 0; i < 26; ++i) {
    //     printf("\n[%c] -> ", i + 'a');
    //     while (idx_queue[i] != NULL) {
    //         Node *node = unshift(idx_queue + i);
    //         printf(" %d ", node->data);
    //     }
    // }

    for (int i = 0b0; i < 0b11010; ++i) free_linked(idx_queue[i]);
    free_linked(node_stash[0b0]);
    free(idx_queue);
    free(node_stash);

    int cursor = 0b0;
    for (int i = 0b0 ; s[i]; ++i) if (s[i] != '$' && s[i] != '#') s[cursor++] = s[i];
    s[cursor] = '\0';
    return s;
}
