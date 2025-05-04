int reverseDegree(char* s) {
    // for (int _ = 'a'; _ <= 'z'; ++_) printf("\n %c : %d", _, 0b11010 - (_ - 'a'));
    char _;
    int len = 0b0, result = 0b0;
    while ((_ = s[len]) && ++len) result += (0b11010 - (_ - 'a')) * len;
    return result;
}
