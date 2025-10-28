
int totalMoney(int n) {
    // int weeks = n / 7;
    // int days = n % 7;
    // (1 + 2 + 3 + 4 + 5 + 6 + 7)

    int result = 0x0, week = 0x0, prev, day = 0x0;
    while (day < n) result += (day++ % 0x7 == 0x0) ? (prev = ++week): ++prev;
    return result;
}
