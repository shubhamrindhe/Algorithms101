struct node {
  double value;
  int index;
};

#define get_parent(index) ((index - 1)>>1)
#define get_left_child(index) ((index<<1) + 1)
#define get_right_child(index) ((index<<1) + 2)

void swap(struct node* a, struct node* b) {
  struct node temp = *a;
  *a = *b;
  *b = temp;
}

void heap_sort(struct node* stack, int* size, int index) {
  // moves up
  int parent = get_parent(index);
  while (index && stack[parent].value < stack[index].value) {
    swap(stack + parent, stack + index);
    index = parent;
    parent = get_parent(index);
  }
  // moves down
  int left = get_left_child(index);
  int right = get_right_child(index);
  while (left < *size && (stack[left].value > stack[index].value || stack[right].value > stack[index].value)) {
    if (*size <= right) right = left;
    if (stack[left].value > stack[right].value) right = left;
    swap(stack + right, stack + index);
    index = right;
    left = get_left_child(index);
    right = get_right_child(index);
  }
}

void heap_insert(struct node* stack, int* size, struct node input) {
  stack[*size] = input;
  heap_sort(stack, size, *size);
  ++(*size);
}

struct node heap_pop(struct node* stack, int* size) {
  struct node result = stack[0];
  stack[0] = stack[*size - 1];
  --(*size);
  heap_sort(stack, size, 0);
  return result;
}

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
  struct node heap[classesSize];
  int heap_size = 0;
  for (int i = 0; i < classesSize; ++i) {
    struct node current;
    current.value = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
    current.value -= (double)(classes[i][0]) / (classes[i][1]);
    current.index = i;
    heap_insert(heap, &heap_size, current);
  }
  
  while (extraStudents) {
    struct node current = heap_pop(heap, &heap_size);
    ++classes[current.index][0];
    ++classes[current.index][1];
    current.value = (double)(classes[current.index][0] + 1) / (classes[current.index][1] + 1);
    current.value -= (double)(classes[current.index][0]) / (classes[current.index][1]);
    heap_insert(heap, &heap_size, current);
    --extraStudents;
  }

  double total = 0;
  for (int i = 0; i < classesSize; ++i) total += (double)classes[i][0] / classes[i][1];
  total /= classesSize;
  return total;
}