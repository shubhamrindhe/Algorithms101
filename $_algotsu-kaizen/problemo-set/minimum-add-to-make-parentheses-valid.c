
int minAddToMakeValid(char* s) {
    int open = 0b0, close = 0b0, len = 0b0, c = '\0';
    while (c = *(s + len++)) {
        open += c == '(' ? 1 : -1;
        if (open < 0) {
            close += 1;
            open = 0;
        }
    }
    return open + close;
}
