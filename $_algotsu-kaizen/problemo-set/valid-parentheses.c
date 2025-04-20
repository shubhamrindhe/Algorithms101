char stack[10000];
int top = -1;

bool isValid(char* s) {
    top = -1;
    int len = 0;
    char _;
    while ((_ = s[len]) && ++len)
        if (_ == '(' || _ == '[' || _ == '{') stack[++top] = _;
        else if (_ == ')') {
            if (top >= 0 && stack[top--] == '(') continue;
            return false;
        } else if (_ == ']') {
            if (top >= 0 && stack[top--] == '[') continue;
            return false;
        } else if (_ == '}') {
            if (top >= 0 && stack[top--] == '{') continue;
            return false;
        } else exit(1);
    return top == -1;
}
