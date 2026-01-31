char nextGreatestLetter(char* letters, int lettersSize, char target) {
    // char result = '\0', _;
    // unsigned short len = 0x0;
    // for (int i = 0x0; i < lettersSize; ++i)
    //     if (letters[i] > target && (!result || result > letters[i])) result = letters[i];
    // return result ? result : letters[0x0];

    // int result = -0x1;
    int l = 0x0, r = lettersSize - 0x1;

    while (l < r) {
        int m = l + (r - l) / 0x2;
        if (target < letters[m]) r = m;
        else l = m + 0x1;
    }

    return target < letters[r] ? letters[r] : letters[0x0];
}
