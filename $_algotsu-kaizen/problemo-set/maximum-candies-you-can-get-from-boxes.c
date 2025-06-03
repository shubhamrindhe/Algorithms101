
typedef struct Queue {
    int* data;
    int length;
    int head;
    int capacity;
} Queue;

Queue* new_queue(int capacity) {
    Queue* queue = (Queue *)calloc(sizeof(Queue), 1);
    queue->data = (int *)calloc(sizeof(int), capacity);
    queue->capacity = capacity;
    return queue;
}

bool isEmpty(Queue *queue) {
    return queue->length == 0;
}

void free_queue(Queue *queue) {
    free(queue->data);
    free(queue);
}

bool enqueue(Queue *queue, int value) {
    if (queue->length >= queue->capacity) return false;
    int tail = (queue->head + queue->length) % queue->capacity;
    queue->data[tail] = value;
    queue->length++;
    return true;
}

int dequeue(Queue *queue) {
    if (queue->length == 0) return -1;
    int value = queue->data[queue->head];
    queue->data[queue->head] = 0;
    queue->head = (queue->head + 1) % queue->capacity;
    queue->length--;
    return value;
}

int first(Queue *queue) {
    if (queue->length == 0) return -1;
    return queue->data[queue->head];
}

void print_queue(Queue *queue) {
    printf("\n");
    // for (int _ = 0; _ < queue->capacity; ++_) printf(" %d ", queue->data[_]);
    for (int _ = 0; _ < queue->length; ++_) printf(" %d ", queue->data[(queue->head + _) % queue->capacity]);
}

int maxCandies(int* status, int statusSize, int* candies, int candiesSize, int** keys, int keysSize, int* keysColSize, int** containedBoxes, int containedBoxesSize, int* containedBoxesColSize, int* initialBoxes, int initialBoxesSize) {
    int N = statusSize;

    bool *available_keys = (bool *)calloc(sizeof(bool), N);
    Queue *open_boxes = new_queue(N);
    Queue *locked_boxes = new_queue(N);
    for (int _ = 0; _ < initialBoxesSize; ++_) {
        int box = initialBoxes[_];
        enqueue(status[box] ? open_boxes : locked_boxes, box);
    }

    int result = 0;

    while (!isEmpty(open_boxes)) {
        // printf("\n\n~~~~~~~~~~~~~~~\n");
        // printf("\nOpen: ");
        // print_queue(open_boxes);
        // printf("\nLocked: ");
        // print_queue(locked_boxes);

        int currentBox = dequeue(open_boxes);
        result += candies[currentBox];

        for (int _ = 0; _ < keysColSize[currentBox]; ++_) available_keys[keys[currentBox][_]] = true;

        // printf("\nKeys: ");
        // for (int _ = 0; _ < N; ++_) printf(" %d ", available_keys[_]);

        for (int _ = 0; _ < containedBoxesColSize[currentBox]; ++_) {
            int new_found_box = containedBoxes[currentBox][_];
            enqueue(status[new_found_box] ? open_boxes : locked_boxes, new_found_box);
        }

        // printf("\nLocked: ");
        // print_queue(locked_boxes);

        int first_locked_box_without_key = -1;
        while (!isEmpty(locked_boxes)) {
            if (first_locked_box_without_key == first(locked_boxes)) break;

            int lockedBox = dequeue(locked_boxes);

            if (status[lockedBox] || available_keys[lockedBox]) {
                enqueue(open_boxes, lockedBox);
            } else {
                if (first_locked_box_without_key == -1) first_locked_box_without_key = lockedBox;
                enqueue(locked_boxes, lockedBox);
            }
        }
    }

    free_queue(open_boxes);
    free_queue(locked_boxes);
    free(available_keys);

    return result;
}
