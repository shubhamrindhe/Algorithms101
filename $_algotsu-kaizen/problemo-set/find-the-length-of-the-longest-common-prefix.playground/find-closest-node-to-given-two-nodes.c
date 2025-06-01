#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

void dfs(int* edges, int edgesSize, int node, int* dist, bool *visited) {
    visited[node] = true;
    int next = edges[node];
    if (next != -1 && !visited[next]) {
        dist[next] = dist[node] + 1;
        dfs(edges, edgesSize, next, dist, visited);
    }

    visited[node] = false;
    // visited[node] = false;
    // dist[node] = MAX(dist[node], dfs(edges, edgesSize, origin, edges[node], dist, visited, step + 1));
    // visited[node] = false;
    // return 0;
}

int closestMeetingNode(int* edges, int edgesSize, int node1, int node2) {
    int n = edgesSize;
    // int *map = (int *)malloc(sizeof(int) * n);
    // for (int _ = 0; _ < n; ++_) map[_] = -1;
    // for (int _ = 0; _ < edgesSize; ++_) map[_] = -1;
    bool *visited = (bool *)calloc(sizeof(bool), n);

    int *dist1 = (int *)calloc(sizeof(int), n);
    for (int _ = 0; _ < edgesSize; ++_) dist1[_] = -1;
    dist1[node1] = 0;
    dfs(edges, edgesSize, node1, dist1, visited);

    // for (int _ = 0; _ < n; ++_) printf("\n %d %d ", _, dist1[_]);

    // printf("\n !!!!!!!!! ");

    int *dist2 = (int *)calloc(sizeof(int), n);
    for (int _ = 0; _ < edgesSize; ++_) dist2[_] = -1;
    dist2[node2] = 0;
    dfs(edges, edgesSize, node2, dist2, visited);

    // for (int _ = 0; _ < n; ++_) printf("\n %d %d ", _, dist2[_]);

    int result = -1, minimus = INT_MAX;

    for (int _ = 0; _ < n; ++_) {
        if (dist1[_] == -1 || dist2[_] == -1) continue;
        int maximus = MAX(dist1[_], dist2[_]);
        if (minimus > maximus) {
            minimus = maximus;
            result = _;
        }
    }

    return result;
}
