
int longestSubsequence(char* s, int k) {
    register int n = 0x0, result = 0x0, i, bitIDX;
    for (i = strlen(s) - 0x1, bitIDX = 0x0; i >= 0x0; --i, ++bitIDX)
        (s[i] == '0' || bitIDX < 0x1F && (n += 0x1 << bitIDX) <= k) && ++result;
    return result;
}
