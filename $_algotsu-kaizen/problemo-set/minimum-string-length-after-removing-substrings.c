
typedef struct {
    char *data;
    int capacity;
    int top;
} Stack;

Stack* new_stack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (char *)malloc(sizeof(char) * size);
    stack->capacity = size;
    stack->top = -1;
    return stack;
}

bool stack_push(Stack * stack, char value) {
    if (stack->top == stack->capacity - 1) return false;
    stack->data[++stack->top] = value;
    return true;
}

char stack_top(Stack * stack) {
    if (stack->top == -1) return '\0';
    return stack->data[stack->top];
}

char stack_pop(Stack * stack) {
    char value = stack->data[stack->top];
    stack->data[stack->top--] = '\0';
    return value;
}

void stack_free(Stack * stack) {
    free(stack->data);
    free(stack);
}

int minLength(char * s){
    char character = '\0';
    int len = 0;
    Stack * stack = new_stack(100);
    while (character = *(s + len++)) {
        switch (character) {
            case 'B':
                if ('A' == stack_top(stack)) {
                    stack_pop(stack);
                    continue;
                }
            break;
            case 'D':
                if ('C' == stack_top(stack)) {
                    stack_pop(stack);
                    continue;
                }
            break;
        }

        stack_push(stack, character);
    }

    int result = stack->top + 1;
    stack_free(stack);
    return result;
}
