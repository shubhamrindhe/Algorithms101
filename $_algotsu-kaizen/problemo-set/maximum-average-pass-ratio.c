
typedef struct Node {
    double ratio;
    int pass;
    int total;
    struct Node *next;
} Node;

Node* new_node(double ratio, int pass, int total, Node* next) {
    Node* node = (Node *)malloc(sizeof(Node));
    node->ratio = ratio;
    node->pass = pass;
    node->total = total;
    node->next = next;
    return node;
}

Node* insert_node(Node* root, Node* node) {
    if (root == NULL) return node; 
    if (root->ratio < node->ratio) {
        node->next = root;
        return node;
    }
    Node* _ = root;
    while (_ && (_->next) && (_->next->ratio > node->ratio)) _ = _->next;
    node->next = _->next;
    _->next = node;
    return root;
}

void print(Node * node) {
    Node* _ = node;
    printf("\n");
    while (_) {
        printf(" %f ", _->ratio);
        _ = _->next;
    }
    printf("\n");
}

/*
double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    double ratioSigma = 0;

    Node* root = new_node(
        ((double)(classes[0][0] + 1) / (classes[0][1] + 1) - (double)(classes[0][0]) / (classes[0][1])),
        classes[0][0],
        classes[0][1],
        NULL
    );

    for (int i = 1; i < classesSize; ++i) {
        double ratio = ((double)(classes[i][0] + 1) / (double)(classes[i][1] + 1) - (double)(classes[i][0]) / (double)(classes[i][1]));
        ratioSigma += ((double)classes[i][0]) / (double)(classes[i][1]);
        root = insert_node(
            root,
            new_node(
                ratio,
                classes[i][0],
                classes[i][1],
                NULL
            )
        );
    }

    for (int i = 0; i < extraStudents; ++i) {
        Node* maxNode = root;
        root = root->next;
        ratioSigma -= (double)maxNode->pass / maxNode->total;
        maxNode->pass = maxNode->pass + 1;
        maxNode->total = maxNode->total + 1;
        ratioSigma += (double)maxNode->pass / maxNode->total;
        int pass = maxNode->pass;
        int total = maxNode->total;
        maxNode->ratio = ((double)(pass + 1) / (double)(total + 1) - (double)pass / (double)total);
        maxNode->next = NULL;
        root = root ? insert_node(root, maxNode) : maxNode; 
    }

    print(root);

    return ratioSigma / classesSize;
}
*/

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    double ratioSigma = 0;

    Node* root = NULL;
    for (int i = 0; i < classesSize; ++i) {
        double delta_ratio = ((double)(classes[i][0] + 1) / (double)(classes[i][1] + 1)) - 
                             ((double)(classes[i][0]) / (double)(classes[i][1]));
        ratioSigma += (double)(classes[i][0]) / (double)(classes[i][1]);
        
        root = insert_node(
            root,
            new_node(delta_ratio, classes[i][0], classes[i][1], NULL)
        );
    }

    for (int i = 0; i < extraStudents; ++i) {
        Node* maxNode = root;
        root = root->next;

        ratioSigma -= (double)maxNode->pass / maxNode->total;
        maxNode->pass += 1;
        maxNode->total += 1;
        ratioSigma += (double)maxNode->pass / maxNode->total;
        
        maxNode->ratio = ((double)(maxNode->pass + 1) / (double)(maxNode->total + 1)) - 
                         ((double)(maxNode->pass) / (double)(maxNode->total));

        root = insert_node(root, maxNode);
    }

    return ratioSigma / classesSize;
}