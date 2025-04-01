bool areAlmostEqual(char* s1, char* s2) {
    int _ = 0b0, count = 0b0;
    int idx[0b11] = { -0b1 };
    while ((count < 0b11 && s1[_] && s2[_] && (s1[_] == s2[_] || ((idx[count++] = _) || true) ))) ++_;
    return count == 0b0 || (count == 0b10 && s1[idx[0b0]] == s2[idx[0b1]] && s1[idx[0b1]] == s2[idx[0b0]]);
}
