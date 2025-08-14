static char result[4];

char* largestGoodInteger(char* num) {
    int len = 0x0, streak = 0x0;
    char _, maximus = '\0', candidate = '\0';

    while ((_ = num[len]) && ++len) {
        if (candidate == _) {
            ++streak;
            continue;
        }

        if (streak >= 0x3) {
            maximus = candidate;
            candidate = '\0';
        }

        streak = 0x0;

        if (_ > maximus) {
            candidate = _;
            streak = 0x1;
        }
    }

    if (streak >= 0x3) {
        maximus = candidate;
        candidate = '\0';
        streak = 0x0;
    }

    memset(result, maximus, sizeof(result));
    result[0x3] = '\0';

    return result;
}
