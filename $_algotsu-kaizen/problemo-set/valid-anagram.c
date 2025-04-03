bool isAnagram(char* s, char* t) {
    int fs[26] = { 0b0 }, ft[26] = { 0b0 }, lens = 0b0, lent = 0b0;
    char cs, ct;

    // while ((cs = s[lens]) && ++lens && (ct = t[lent]) && ++lent) {
    //     ++fs[cs - 'a'];
    //     ++ft[ct - 'a'];
    // }

    while ((cs = s[lens]) && ++lens) ++fs[cs - 'a'];
    while ((ct = t[lent]) && ++lent) ++ft[ct - 'a'];

    if (cs || ct || (lens != lent)) return false;

    for (int _ = 0; _ < 26; ++_) if (fs[_] != ft[_]) return false;

    return true;
}
