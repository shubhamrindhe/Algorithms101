#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

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

void print_queue(Queue *queue) {
    printf("\n");
    for (int _ = 0; _ < queue->capacity; ++_) printf(" %d ", queue->data[_]);
}

int cell_idx(int r, int c, int N) {
    int row_from_bottom = N - 1 - r;
    int index = row_from_bottom * N + (row_from_bottom % 2 ? (N - 1 - c) : c);
    return index + 1;
}

int idx_to_row(int idx, int N) {
    idx -= 1;
    int row_from_bottom = idx / N;
    return N - 1 - row_from_bottom;
}

int idx_to_column(int idx, int N) {
    idx -= 1;
    int row_from_bottom = idx / N;
    int col_in_row = idx % N;
    return row_from_bottom % 2 ? (N - 1 - col_in_row) : col_in_row;
}

// int dfs(int** board, int N, int position) {
//     if (N * N - position <= 6) return 1;
//     for (int cell = position + 1; ; cell) {
//     }
// }

int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    int N = boardSize, destination = N * N;
    int *rolls = (int *)malloc(sizeof(int) * (destination + 1));
    for (int _ = 0; _ < destination + 1; ++_) rolls[_] = -1;
    rolls[1] = 0;

    // for (int r = 0; r < N; ++r) {
    //     printf("\n");
    //     for (int c = 0; c < N; ++c) {
    //         int idx = cell_idx(r, c, N);
    //         // printf(" %d ", idx);
    //         printf(" ( %d, %d ) ", idx_to_row(idx, N), idx_to_column(idx, N));
    //     }
    // }

    Queue *q = new_queue(destination + 1);
    enqueue(q, 1);

    // enqueue(q, 1);
    // enqueue(q, 2);
    // enqueue(q, 3);
    // enqueue(q, 4);
    // enqueue(q, 5);
    // print_queue(q);
    // dequeue(q);
    // dequeue(q);
    // print_queue(q);
    // enqueue(q, 6);
    // enqueue(q, 7);
    // enqueue(q, 8);
    // enqueue(q, 9);
    // enqueue(q, 10);
    // print_queue(q);
    // dequeue(q);
    // dequeue(q);
    // print_queue(q);
    // enqueue(q, 11);
    // enqueue(q, 12);
    // enqueue(q, 13);
    // print_queue(q);

    int result = -1;
    bool end = false;

    while (!isEmpty(q) && !end) {
        int curr = dequeue(q);
        for (int next = curr + 1; next <= MIN(curr + 6, destination); ++next) {
            int r = idx_to_row(next, N), c = idx_to_column(next, N);

            int next_ = board[r][c] != -1 ? board[r][c] : next;

            if (next_ == destination) {
                result = rolls[curr] + 1;
                end = true;
                break;
            }

            if (rolls[next_] == -1) {
                rolls[next_] = rolls[curr] + 1;
                enqueue(q, next_);
            }
        }
    }

    free_queue(q);
    free(rolls);

    return result;
}
