#define SIZE 0b11010

typedef struct DisjointSet {
    char* parent;
} DisjointSet;

DisjointSet* new_disjoint_set(int size) {
    DisjointSet* disjointSet = malloc(sizeof(DisjointSet));
    disjointSet->parent = (char *)malloc(size * sizeof(char));
    for (char _ = '\0'; _ < size; ++_) disjointSet->parent[_] = _;
    return disjointSet;
}

void free_disjoint_set(DisjointSet* disjointSet) {
    free(disjointSet->parent);
    free(disjointSet);
}

char FIND(DisjointSet* disjointSet, char x) {
    return disjointSet->parent[x] == x ? x : FIND(disjointSet, disjointSet->parent[x]);
}

void UNION(DisjointSet* disjointSet, char x, char y) {
    char rootX = FIND(disjointSet, x);
    char rootY = FIND(disjointSet, y);
    if (rootX == rootY) return;
    if (rootX < rootY) {
        disjointSet->parent[rootY] = rootX;
    } else {
        disjointSet->parent[rootX] = rootY;
    }
}

char* smallestEquivalentString(char* s1, char* s2, char* baseStr) {
    // char** minion_set = (char**)calloc(sizeof(char*), 26);
    DisjointSet* disjointSet = new_disjoint_set(SIZE);
    char c1 = '\0', c2 = '\0';
    int len = 0b0;
    while ((c1 = s1[len]) && (c2 = s2[len]) && ++len) {
        if (c1 == c2) continue;
        UNION(disjointSet, c1 - 'a', c2 - 'a');
    }

    // for (int _ = 0; _ < 26; ++_)
    //     printf(" (%c, %d) ", _ + 'a', disjointSet->parent[_]);
    char equivalent_minimus[SIZE] = { '\0' };
    for (int _ = 0b0; _ < SIZE; ++_) equivalent_minimus[_] = FIND(disjointSet, _) + 'a';

    free_disjoint_set(disjointSet);

    char _ = '\0';
    int idx = 0b0;
    while (_ = baseStr[idx]) baseStr[idx++] = equivalent_minimus[_ - 'a'];

    return baseStr;
}
