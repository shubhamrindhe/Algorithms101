typedef struct Node {
    unsigned long data;
    int idx;
    struct Node *next;
} Node;

Node* new_node(unsigned long data, int idx, Node* next) {
    Node* node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->idx = idx;
    node->next = next;
    return node;
}

Node* insert_node(Node* root, Node* node) {
    if (root == NULL) return node;
    if (root->data > node->data || (root->data == node->data && root->idx > node->idx)) {
        node->next = root;
        return node;
    }
    Node* _ = root;
    while (
        _
        && (_->next)
        && (
            (_->next->data < node->data)
            ||
            ((_->next->data == node->data) && (_->next->idx < node->idx))
        )
    ) _ = _->next;
    node->next = _->next;
    _->next = node;
    return root;
}

void free_list(Node* root) {
    while (root) {
        Node* tmp = root;
        root = root->next;
        free(tmp);
    }
}

int cmp_meetings(const void* a, const void* b) {
    int* m1 = *(int**)a;
    int* m2 = *(int**)b;
    if (m1[0] != m2[0])
        return m1[0] - m2[0];
    return m1[1] - m2[1];
}

int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize) {
    qsort(meetings, meetingsSize, sizeof(int*), cmp_meetings);

    Node* empty_rooms = NULL;
    for (int i = 0; i < n; ++i) {
        empty_rooms = insert_node(empty_rooms, new_node(0, i, NULL));
    }

    Node* busy_rooms = NULL;
    int* booking_count = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < meetingsSize; ++i) {
        int start = meetings[i][0];
        int end = meetings[i][1];

        while (busy_rooms && busy_rooms->data <= start) {
            Node* freed_room = busy_rooms;
            busy_rooms = busy_rooms->next;
            empty_rooms = insert_node(empty_rooms, new_node(0x0, freed_room->idx, NULL));
            free(freed_room);
        }

        if (empty_rooms) {
            Node* assigned = empty_rooms;
            empty_rooms = empty_rooms->next;

            int room_id = assigned->idx;
            booking_count[room_id]++;
            busy_rooms = insert_node(busy_rooms, new_node(end, room_id, NULL));

            free(assigned);
        } else {
            Node* assigned = busy_rooms;
            busy_rooms = busy_rooms->next;

            int room_id = assigned->idx;
            int delay = assigned->data;

            int duration = end - start;
            unsigned long new_end = (unsigned long)delay + duration;

            booking_count[room_id]++;
            busy_rooms = insert_node(busy_rooms, new_node(new_end, room_id, NULL));

            free(assigned);
        }
    }

    int max_bookings = 0;
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        // printf("%d ", booking_count[i]);
        if (booking_count[i] > max_bookings) {
            max_bookings = booking_count[i];
            answer = i;
        }
    }

    free(booking_count);
    free_list(empty_rooms);
    free_list(busy_rooms);

    return answer;
}