int minPartitions(char* n) {
    char _ = '\x00', max = '\x00';
    int len = 0x0;
    while ((_ = n[len]) && ++len) (max < _) && (max = _);
    return max - '0';
}

// [00...09] -> 1 * n;
// [11...99] -> (_,_)
