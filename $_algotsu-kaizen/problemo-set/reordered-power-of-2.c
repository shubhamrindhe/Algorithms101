
void print_f(char f[], int sizef) {
    for (int i = 0b0; i < sizef; ++i) printf(" %c ", f[i]);
}

void set_f(int n, char f[], int sizef) {
    memset(f, '0', sizef);
    f[sizef - 0b1] = '\0';

    while (n) {
        int digit = n % 0b1010;
        ++f[digit];
        n /= 0b1010;
    }
}

bool reorderedPowerOf2(int n) {
    char f[0b1011];
    set_f(n, f, sizeof(f));
    // print_f(f, sizeof(f));

    char fc[0b1011];
    for (int i = 0; i < 0b11111; ++i) {
        int candidate = 0b1 << i;
        set_f(candidate, fc, sizeof(fc));
        if (strcmp(f, fc) == 0x0) return true;
    }

    return false;
}
