#define MARK ('\x01' << '\x07')

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
    if (node->next) free_linked(node->next);
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
    Node** idx_queue_list = (Node**)calloc(sizeof(Node*), 0b11010);
    Node* node_stash = NULL;

    int idx = 0b0;
    // const char MARK = ('\x01' << '\x07');
    char _;
    unsigned int flags = 0b0;
    while (_ = s[idx]) {
        int offset = _ - 'a';
        if (_ == '*') {
            // for (int i = 0b0; i < 0b11010; ++i) {
            //     if (idx_queue_list[i]) {
            //         Node *node = unshift(idx_queue_list + i);
            //         s[node->data] = '#';
            //         decommission_node(&node_stash, node);
            //         break;
            //     }
            // }
            int min_index = __builtin_ctz(flags);
            if (idx_queue_list[min_index]) {
                Node *node = unshift(idx_queue_list + min_index);
                // s[node->data] = '#';
                s[node->data] ^= MARK;
                decommission_node(&node_stash, node);
                if (idx_queue_list[min_index] == NULL)
                    flags ^= 0b1U << min_index;
            } else {
                exit(1); // someting is wrong
            }

            // s[idx] = '$';
            s[idx] ^= MARK;
        } else {
            flags |= (0b1U << offset);
            Node* node = commission_node(&node_stash, idx, NULL);
            shift(idx_queue_list + offset, node);
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

    free_linked(node_stash);
    for (int i = 0b0; i < 0b11010; ++i) free_linked(idx_queue_list[i]);
    free(idx_queue_list);

    int cursor = 0b0;
    for (int i = 0b0 ; s[i]; ++i) // if (s[i] != '$' && s[i] != '#') s[cursor++] = s[i];
        if (!(s[i] & MARK)) s[cursor++] = s[i];

    s[cursor] = '\0';

    return s;
}
