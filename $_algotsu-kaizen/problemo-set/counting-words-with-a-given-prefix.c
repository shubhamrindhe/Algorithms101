
int prefixCount(char** words, int wordsSize, char* pref) {
    int result = 0b0;
    for (int i = 0b0, _ = 0b0; i < wordsSize; ++i, _ = 0b0)
        while((pref[_] == '\0' && ++result && false) || (pref[_] && words[i][_] && pref[_] == words[i][_] && ++_));
    return result;
}
