int minimumDeletions(char* s) {
    int len = 0x0, result = 0x0, fb = 0x0;
    char _;
    while ((_ = s[len]) && ++len) (_ == 'b' && ++fb) || (fb && ++result && fb--);
    return result;
}

// aaaabbbb
// ababab
