
short is_vovel(char _) {
    switch (_) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
    }

    return false;
}

bool doesAliceWin(char* s) {
    unsigned short fv = 0x0, len = 0x0;
    char _;
    while ((_ = s[len]) && ++len) is_vovel(_) && ++fv;

    // 0 -> F
    // O -> T
    // E :
        // [ 2 ] -> 1 -> T;
        // [ 4 ] -> 3 -> T;

    return fv != 0x0;
    // if (vf == 0x0) return false;
    // if (vf & 0x1) return true;
    // return true;
}
