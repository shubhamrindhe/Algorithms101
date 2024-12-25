
long long minimumSteps(char* s) {
    long long result = 0b0;
    for (int l = 0b0, r = 0b0; s[r]; ++r) if (s[r] == '0') result += r - l++;
    return result;
}
