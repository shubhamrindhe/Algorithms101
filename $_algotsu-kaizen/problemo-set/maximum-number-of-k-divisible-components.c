// long dfs(int node, int parent, int n, int k, bool **adj_matrix, int* values, int* counter_pointer) {
//     long total = values[node];
//     for (int i = 0 ; i < n; ++i)
//         if (adj_matrix[node][i] && i != parent)
//             total += dfs(i, node, n, k, adj_matrix, values, counter_pointer);
//     if (total % k == 0) ++(*counter_pointer);
//     return total;
// }

typedef struct Node {
  int idx;
  struct Node *next;
} Node;

Node* new_node(int idx, Node* next) {
    Node* node = (Node *)malloc(sizeof(Node));
    node->idx = idx;
    node->next = next;
    return node;
}

long dfs_(int node, int parent, int n, int k, Node **adj_list, int* values, int* counter_pointer) {
    long total = values[node];
    Node* _ = adj_list[node];
    while (_) {
        if (_->idx != parent)
            total += dfs_(_->idx, node, n, k, adj_list, values, counter_pointer);
        _ = _->next;
    }
    if (total % k == 0) ++(*counter_pointer);
    return total;
}

int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, int* values, int valuesSize, int k) {
    // bool **adj_matrix = (bool**)malloc(n * sizeof(bool*));
    // for (int i = 0; i < n; ++i) adj_matrix[i] = (bool *)calloc(n, sizeof(bool));
    Node** nodes = (Node **)calloc(n, sizeof(Node *));

    for (int e = 0; e < edgesSize; ++e) {
        int from = edges[e][0], to = edges[e][1];
        // adj_matrix[from][to] = true;
        // adj_matrix[to][from] = true;
        nodes[from] = new_node(to, nodes[from]);
        nodes[to] = new_node(from, nodes[to]);
    }

    int result = 0;
    // dfs(0, -1, n, k, adj_matrix, values, &result);
    dfs_(0, -1, n, k, nodes, values, &result);

    // for (int i = 0; i < n; ++i) free(adj_matrix[i]);
    // free(adj_matrix);
    for (int i = 0; i < n; ++i) {
        Node* _ = nodes[i];
        while (_) {
            Node* __ = _->next;
            free(_);
            _ = __;
        }
    }
    free(nodes);

    return result;
}
