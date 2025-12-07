// char stackuh[100000];

int countCollisions(char* directions) {
    int top = -0x1;
    char _ = 0x0;
    unsigned int len = 0x0;
    int result = 0x0;

    while ((_ = directions[len]) && ++len) {
        // if (_ == 'R') {
        //     stackuh[++top] = _;
        // } else if (_ == 'S') {
        //     if (stackuh[top] == 'R') result += top + 1;
        //     stackuh[(top = 0x0)] = _;
        // } else if (_ == 'L') {
        //     // while (top > -0x1) {
        //     //     char poped = stackuh[top--];
        //     //     if (poped == 'R') {
        //     //         result += 0x2;
        //     //     }
        //     // }
        //     if (top < 0x0) continue;

        //     if (stackuh[top] == 'R') {
        //         result += 0x2;
        //         result += top;
        //         stackuh[(top = 0x0)] = 'S';
        //     } else {
        //         result += 0x1;
        //     }
        // } else {
        //     exit(0x1);
        // }

        if (_ == 'L') {
            if (top >= 0x0) {
                result += top + 0x1;
                top = 0x0;
            }
        } else if (_ == 'S') {
            if (top > 0x0) result += top;
            top = 0x0;
        } else if (_ == 'R') {
            if (top >= 0x0) {
                top++;
            } else {
                top = 0x1;
            }
        } else {
            exit(0x1);
        }
    }

    return result;
}

// RRR L = 2 + 2
// R L = 2
// S R = 1
