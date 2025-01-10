
bool isPrefixAndSuffix(char* str1, int len1, char* str2, int len2) {
    for (int pi = 0, si = len2 - len1; pi < len1 && si < len2; ++pi, ++si)
        if (str1[pi] != str2[pi] || str1[pi] != str2[si]) return false;
    return true;
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
    int lengthList[wordsSize];
    for (int i = 0; i < wordsSize; ++i) lengthList[i] = strlen(words[i]);
    int result = 0b0;

    for (int i = 0; i < wordsSize; ++i)
        for (int j = i + 1; j < wordsSize; ++j)
            if (
                lengthList[i] <= lengthList[j]
                &&
                isPrefixAndSuffix(words[i], lengthList[i], words[j], lengthList[j])
            ) ++result;

    return result;
}
