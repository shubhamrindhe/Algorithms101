
typedef struct {
    int start;
    int end;
    struct Node *left;
    struct Node *right;
} Node;

void free_node(Node *node) {
    if (node == NULL) return;
    free_node(node->left);
    free_node(node->right);
    free(node);
}

Node* new_node(int start, int end) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->start = start;
    node->end = end;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool insert(Node* node, int start, int end) {
    if (start >= node->end) {
        if (node->right != NULL) return insert(node->right, start, end);
        node->right = new_node(start, end);
        return true;
    } else if (end <= node->start) {
        if (node->left != NULL) return insert(node->left, start, end);
        node->left = new_node(start, end);
        return true;
    }

    return false;
}

typedef struct {
    Node *root;
} MyCalendar;

MyCalendar* myCalendarCreate() {
    MyCalendar *myCalendar = (MyCalendar *)malloc(sizeof(MyCalendar));
    myCalendar->root = NULL;
    return myCalendar;
}

bool myCalendarBook(MyCalendar* calendar, int start, int end) {
    if (calendar->root == NULL) {
        calendar->root = new_node(start, end);
        return true;
    }

    return insert(calendar->root, start, end);
}

void myCalendarFree(MyCalendar* obj) {
    free_node(obj->root);
    free(obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);

 * myCalendarFree(obj);
*/
