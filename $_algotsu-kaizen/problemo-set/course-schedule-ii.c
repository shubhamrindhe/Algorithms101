
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

bool topological_sort_dfs(AdjacencyDS *adjacencyMatrix, int node, bool* path, bool* visited, int *stack, int* top) {
    if (path[node]) return true;
    if (visited[node]) return false;
    visited[node] = (path[node] = true);
    for (int _ = 0; _ < adjacencyMatrix->sizes[node]; ++_) {
        int adj_node = adjacencyMatrix->data[node][_];
        if (topological_sort_dfs(adjacencyMatrix, adj_node, path, visited, stack, top)) {
            return true;
        }
    }
    stack[(*top)++] = node;
    return (path[node] = false);
}

int* topological_sort(AdjacencyDS *adjacencyMatrix) {
    bool* path = (bool *)calloc(sizeof(bool), adjacencyMatrix->nodes_count);
    bool* visited = (bool *)calloc(sizeof(bool), adjacencyMatrix->nodes_count);
    int *stack = (int *)calloc(sizeof(int), adjacencyMatrix->nodes_count);
    int top = 0;
    for (int node = 0; node < adjacencyMatrix->nodes_count; ++node)
        if ((!visited[node]) && topological_sort_dfs(adjacencyMatrix, node, path, visited, stack, &top))
            return NULL;
    return stack;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    AdjacencyDS *adjacencyMatrix = new_adjacency_matrix(numCourses);
    int *result = (int*)calloc(sizeof(int), numCourses);
    *returnSize = 0;
    if (fill_adjacency_list(adjacencyMatrix, prerequisites, prerequisitesSize)) return result;
    int *sorted = topological_sort(adjacencyMatrix);
    if (sorted == NULL) return result;
    for (int n = numCourses - 1; n >= 0; --n) result[(*returnSize)++] = sorted[n];
    return result;
}
