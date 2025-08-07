#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

char* makeFancyString(char* s) {
    int count = 0x0, len = 0x0, ptr = 0x0;
    char _, _1 = '\0';

    while ((_ = s[len]) && ++len) {
        if (_ == _1) {
            ++count;
            continue;
        }

        for (int i = 0; _ && i < MIN(2, count); ++i) s[ptr++] = _1;
        _1 = _;
        count = 1;
    }

    for (int i = 0; i < MIN(2, count); ++i) s[ptr++] = _1;
    s[ptr++] = '\0';

    return s;
}
