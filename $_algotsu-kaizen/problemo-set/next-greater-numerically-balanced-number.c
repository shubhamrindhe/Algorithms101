char f_hash[0xB] = { '\x00' };
char digit_buffer[0xB] = { '\x00' };
const char balanced_hash[0xB] = "0000000000";

bool isBalanced(int x) {
    char len = '\x00';
    memset(f_hash, '0', 0xA);
    memset(digit_buffer, '\0', sizeof(digit_buffer));

    while (x) {
        int digit = (x % 0xA);
        (f_hash[digit] == '0') && (f_hash[digit] -= digit);
        // digit_buffer[len++] = digit + '0'; // /* [1] */
        digit_buffer[len++] = digit;
        x /= 0xA;
    }
    // printf("\n %s [ %d ]\n", digit_buffer, len);

    // char _, i = 0x0; // /* [1] */
    // while ((_ = digit_buffer[i]) && ++i) ++f_hash[_ - '0'];


    char IDX = len - 0x1;
    while (IDX >= 0x0) ++f_hash[digit_buffer[IDX--]];


    // printf("[%s]\n", f);
    return strcmp(f_hash, balanced_hash) == 0x0;
    // return memcmp(f_hash, balanced_hash, sizeof(balanced_hash)) == 0x0;
}

int nextBeautifulNumber(int n) {
    // printf(">>> %d", isBalanced(n));
    do ++n; while(!isBalanced(n));
    return n;
}
