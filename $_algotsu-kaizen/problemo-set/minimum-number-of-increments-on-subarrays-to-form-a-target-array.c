int minNumberOperations(int* target, int targetSize) {
    int stack[targetSize], top = -0x1;
    // memset(stack, 0x0, sizeof(stack));
    int result = 0x0;

    for (int i = 0x0; i < targetSize; ++i) {
        int current = target[i];
        while (top >= 0x0 && stack[top] > current) {
            int popedValue = stack[top--];
            if (top < 0x0 || stack[top] < current) stack[++top] = current;
            result += popedValue - (top >= 0x0 ? stack[top] : current);
        }

        if (top < 0x0 || stack[top] < current)
            stack[++top] = current;
    }

    while (top >= 0x0) {
        int popedValue = stack[top--];
        result += popedValue - (top >= 0x0 ? stack[top] : 0x0);
    }

    return result;
}


// []
// 1 [1]
// 2 [1,2]
// 3 [1,2,3]
// 2 [1,2] +1
// 1 [1] +1
// [] +1
