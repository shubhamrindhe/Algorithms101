
int countConsistentStrings(char * allowed, char ** words, int wordsSize) {
    int idx = 0b0;
    unsigned int mask = 0b0, bit = 0b1;
    while (*(allowed + idx)) mask |= bit << (*(allowed + idx++) - 'a');

    int count = 0b0;
    for (int i = 0b0; i < wordsSize; ++i) {
        bool flag = true;
        idx = 0b0;
        while ( *(*(words + i) + idx) ) {
            if ((bit << (*(*(words + i) + idx++) - 'a')) & mask) {
                continue;
            } else {
                flag = false;
                break;
            }
        }
        flag && ++count;
    }

    return count;
}
