char paper[100001];
char stack[100001];

char* robotWithString(char* s) {
    int f[26] = { 0 };
    char _;
    int len = 0;

    int p_len = 0;
    int stack_top = -1;

    while ((_ = s[len]) && ++len) ++f[_ - 'a'];

    char c = 'a';
    for (int i = 0; i < len; ++i) {
        stack[++stack_top] = s[i];
        f[s[i] - 'a']--;
        while (c < 'z' && f[c - 'a'] == 0) ++c;
        while (stack_top > -1 && stack[stack_top] <= c)
            paper[p_len++] = stack[stack_top--];
    }

    paper[len] = '\0';

    return paper;
}
