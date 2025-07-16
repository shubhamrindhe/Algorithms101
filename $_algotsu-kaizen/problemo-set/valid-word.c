bool isValid(char* word) {
    register char _, len = 0, v = false, c = false;

    while ((_ = word[len]) && ++len) {
        if (_ >= '0' && _ <= '9') continue;
        bool lower = (_ >= 'a' && _ <= 'z');
        bool upper = (_ >= 'A' && _ <= 'Z');
        if (!lower && !upper) return false;
        if (v && c) continue;
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
                v = true;
                break;
            default:
                c = true;
                break;
        }
    }

    // printf("%d %d %d",len, v, c);
    return len >= 3 && v && c;
}
