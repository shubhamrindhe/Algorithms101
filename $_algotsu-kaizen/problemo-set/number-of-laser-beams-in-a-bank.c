int numberOfBeams(char** bank, int bankSize) {
    int lazers = 0x0, len, currentLazerCount;
    char _;

    int result = 0x0;

    for (int i = 0x0; i < bankSize; ++i) {
        len = 0x0, currentLazerCount = 0x0;
        while ((_ = bank[i][len]) && ++len) if (_ == '1') ++currentLazerCount;

        if (currentLazerCount) {
            result += currentLazerCount * lazers;
            lazers = currentLazerCount;
        }
    }

    return result;
}
