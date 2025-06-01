
typedef struct AdjacencyDS {
    int** data;
    int nodes_count;
    int* sizes;
} AdjacencyDS;

AdjacencyDS *new_adjacency_matrix(int n) {
    AdjacencyDS *adjacencyMatrix = (AdjacencyDS *)malloc(sizeof(AdjacencyDS));
    adjacencyMatrix->data = (int**)malloc(sizeof(int*) * n);
    for (int _ = 0; _ < n; ++_) adjacencyMatrix->data[_] = (int*)calloc(sizeof(int), n);
    adjacencyMatrix->sizes = (int*)calloc(sizeof(int), n);
    adjacencyMatrix->nodes_count = n;
    return adjacencyMatrix;
}

bool fill_adjacency_matrix(AdjacencyDS *adjacencyMatrix, int** edges, int edges_size) {
    bool self_cycle_flag = false;
    for (int _ = 0; _ < edges_size; ++_) {
        int u = edges[_][1], v = edges[_][0];
        adjacencyMatrix->data[u][v] = 1;
        if (u == v) self_cycle_flag = true;
    }
    return self_cycle_flag;
}

void print_adjacency_matrix(AdjacencyDS *adjacencyMatrix) {
    printf("\n");
    for (int u = 0; u < adjacencyMatrix->nodes_count; ++u) {
        printf("\n");
        for (int v = 0; v < adjacencyMatrix->nodes_count; ++v) {
            printf(" %c ", adjacencyMatrix->data[u][v] ? '#' : '-');
        }
    }
}

bool fill_adjacency_list(AdjacencyDS *adjacencyMatrix, int** edges, int edges_size) {
    bool self_cycle_flag = false;
    for (int _ = 0; _ < edges_size; ++_) {
        int u = edges[_][1], v = edges[_][0];
        adjacencyMatrix->data[u][
            (adjacencyMatrix->sizes[u])++
        ] = v;
        if (u == v) self_cycle_flag = true;
    }
    return self_cycle_flag;
}

void print_adjacency_list(AdjacencyDS *adjacencyMatrix) {
    printf("\n");
    for (int u = 0; u < adjacencyMatrix->nodes_count; ++u) {
        printf("\n [%d]: ", u);
        for (int v = 0; v < adjacencyMatrix->sizes[u]; ++v) {
            printf(" %d ", adjacencyMatrix->data[u][v]);
        }
    }
}

bool detect_cycle_rec(AdjacencyDS *adjacencyMatrix, int node, bool* stack, bool* visited) {
    if (stack[node]) return true;
    if (visited[node]) return false;
    visited[node] = (stack[node] = true);
    for (int _ = 0; _ < adjacencyMatrix->sizes[node]; ++_) {
        int adj_node = adjacencyMatrix->data[node][_];
        if (detect_cycle_rec(adjacencyMatrix, adj_node, stack, visited)) return true;
    }
    return (stack[node] = false);
}

bool detect_cycle(AdjacencyDS *adjacencyMatrix) {
    bool* stack = (bool *)calloc(sizeof(bool), adjacencyMatrix->nodes_count);
    bool* visited = (bool *)calloc(sizeof(bool), adjacencyMatrix->nodes_count);
    for (int node = 0; node < adjacencyMatrix->nodes_count; ++node)
        if ((!visited[node]) && detect_cycle_rec(adjacencyMatrix, node, stack, visited))
            return true;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    AdjacencyDS *adjacencyMatrix = new_adjacency_matrix(numCourses);
    // if (fill_adjacency_matrix(adjacencyMatrix, prerequisites, prerequisitesSize)) return false;
    // print_adjacency_matrix(adjacencyMatrix);
    if (fill_adjacency_list(adjacencyMatrix, prerequisites, prerequisitesSize)) return false;
    // print_adjacency_list(adjacencyMatrix);
    // fill_adjacency_list(adjacencyMatrix, prerequisites, prerequisitesSize);
    return !detect_cycle(adjacencyMatrix);
}
