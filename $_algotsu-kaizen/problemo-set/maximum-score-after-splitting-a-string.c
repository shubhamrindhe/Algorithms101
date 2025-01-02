
int maxScore(char* s) {
    int len = 0b0;
    char _ = '\0';
    while ((_ = s[len]) && ++len);
    int presum[500] = { 0b0 };

    int uno = 0b0;
    for (int i = 0b0; i < len; ++i) {
        if (s[i] == '1') ++uno;
        presum[i] = uno;
    }

    int result = 0b0;

    len == 0b10 && *s == '0' && ++result;
    len == 0b10 && *(s+1) == '1' && ++result;

    for (int i = 0b1; i < len - 0b1; ++i) {
        int shunya = i + 1 - presum[i], ekam = uno - presum[i - 1];
        if (shunya + ekam > result) result = shunya + ekam;
    }

    return result;
}
