char kthCharacter(int k) {
    char s[0x1F4] = { '\0' }, result;
    s[0x0] = 'a';
    int len = 0x1;
    bool stop = false;

    while (!stop) {
        for (int i = 0x0; !stop && i < len; ++i) {
            s[len + i] = s[i] == 'z' ? 'a' : s[i] + 0x1;
            if (len + i >= k - 0x1) result = s[k - (stop = true)];
        }

        // printf("\n%s", s);
        len *= 0x2;
    }

    return result;
}
