char* getSmallestString(char* s) {
    unsigned int len = 0x0;
    char _, prev = '\0';

    while ((_ = s[len]) && ++len) {
        if (prev > _) {
            if ((prev & 0b1) == (_ & 0b1)) {
            // if ((prev ^ _ ^ 0b1) == 0x1) {
                int curr_idx = len - 0x1;
                int prev_idx = curr_idx - 0x1;
                // printf("[ %c, %c]", prev, _);
                s[curr_idx] = prev;
                s[prev_idx] = _;
                break;
            }
        }

        prev = _;
    }

    return s;
}
